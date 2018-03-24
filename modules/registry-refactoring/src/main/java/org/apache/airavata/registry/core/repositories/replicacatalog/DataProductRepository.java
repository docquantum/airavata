/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
*/
package org.apache.airavata.registry.core.repositories.replicacatalog;

import org.apache.airavata.model.data.replica.DataProductModel;
import org.apache.airavata.model.data.replica.DataProductType;
import org.apache.airavata.registry.core.entities.replicacatalog.DataProductEntity;
import org.apache.airavata.registry.core.utils.DBConstants;
import org.apache.airavata.registry.core.utils.QueryConstants;
import org.apache.airavata.registry.cpi.ReplicaCatalog;
import org.apache.airavata.registry.cpi.ReplicaCatalogException;
import org.apache.airavata.registry.core.utils.ObjectMapperSingleton;
import org.dozer.Mapper;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.sql.Timestamp;
import java.util.*;

public class DataProductRepository extends RepCatAbstractRepository<DataProductModel, DataProductEntity, String> {
    private final static Logger logger = LoggerFactory.getLogger(DataProductRepository.class);

    public DataProductRepository() {
        super(DataProductModel.class, DataProductEntity.class);
    }

    protected String saveDataProductModelData(DataProductModel dataProductModel) throws ReplicaCatalogException {
        DataProductEntity dataProductEntity = saveDataProduct(dataProductModel);
        return dataProductEntity.getProductUri();
    }

    protected DataProductEntity saveDataProduct(DataProductModel dataProductModel) throws ReplicaCatalogException {
        String productUri = ReplicaCatalog.schema + "://" + UUID.randomUUID().toString();
        dataProductModel.setProductUri(productUri);
        Mapper mapper = ObjectMapperSingleton.getInstance();
        DataProductEntity dataProductEntity = mapper.map(dataProductModel, DataProductEntity.class);

        if (dataProductEntity.getOwnerName() == null || dataProductEntity.getGatewayId() == null) {
            logger.error("Owner name and/or gateway ID is empty");
            throw new ReplicaCatalogException("Owner name and gateway ID should not be empty");
        }

        if (dataProductEntity.getParentProductUri() != null && (!isExists(dataProductEntity.getParentProductUri())
                || !getDataProduct(dataProductEntity.getParentProductUri()).getDataProductType().equals(DataProductType.COLLECTION))) {
            logger.error("Parent product does not exist and/or parent type is not Collection");
            throw new ReplicaCatalogException("Parent product does not exist or parent type is not Collection");
        }

        if (dataProductEntity.getReplicaLocations() != null) {
            logger.debug("Populating the product URI for ReplicaLocations objects for the Application Deployment");
            dataProductEntity.getReplicaLocations().forEach(dataReplicaLocationEntity -> dataReplicaLocationEntity.setProductUri(productUri));
        }

        if (!isDataProductExists(productUri)) {
            logger.debug("Checking if the Data Product already exists");
            dataProductEntity.setCreationTime(new Timestamp(System.currentTimeMillis()));
        }

        dataProductEntity.setLastModifiedTime(new Timestamp(System.currentTimeMillis()));

        return execute(entityManager -> entityManager.merge(dataProductEntity));

    }

    public String registerDataProduct(DataProductModel dataProductModel) throws ReplicaCatalogException {
        return saveDataProductModelData(dataProductModel);
    }

    public void updateDataProduct(DataProductModel updatedDataProductModel) throws ReplicaCatalogException {
        saveDataProductModelData(updatedDataProductModel);
    }

    public DataProductModel getDataProduct(String productUri) throws ReplicaCatalogException {
        return get(productUri);
    }

    public DataProductModel getParentDataProduct(String productUri) throws ReplicaCatalogException {
        DataProductModel dataProductModel = getDataProduct(productUri);
        return get(dataProductModel.getParentProductUri());
    }

    public List<DataProductModel> getChildDataProducts(String parentProductUri) throws ReplicaCatalogException {
        Map<String, Object> queryParameters = new HashMap<>();
        queryParameters.put(DBConstants.DataProduct.PARENT_PRODUCT_URI, parentProductUri);
        List<DataProductModel> dataProductModelList = select(QueryConstants.FIND_ALL_CHILD_DATA_PRODUCTS, -1, 0, queryParameters);
        return dataProductModelList;
    }

    public List<DataProductModel> searchDataProductsByName(String gatewayId, String userId, String productName,
                                                    int limit, int offset) throws ReplicaCatalogException {
        Map<String, Object> queryParameters = new HashMap<>();
        queryParameters.put(DBConstants.DataProduct.GATEWAY_ID, gatewayId);
        queryParameters.put(DBConstants.DataProduct.OWNER_NAME, userId);
        queryParameters.put(DBConstants.DataProduct.PRODUCT_NAME, productName);
        List<DataProductModel> dataProductModelList = select(QueryConstants.FIND_DATA_PRODUCT_BY_NAME, limit, offset, queryParameters);
        return dataProductModelList;
    }

    public boolean isDataProductExists(String productUri) throws ReplicaCatalogException {
        return isExists(productUri);
    }

    public boolean removeDataProduct(String productUri) throws ReplicaCatalogException {
        return delete(productUri);
    }

}
