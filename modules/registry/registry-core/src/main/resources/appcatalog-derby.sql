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

CREATE TABLE COMPUTE_RESOURCE
(
        RESOURCE_ID VARCHAR (255) NOT NULL,
        HOST_NAME VARCHAR (255) NOT NULL,
        RESOURCE_DESCRIPTION VARCHAR (255),
        CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
        MAX_MEMORY_NODE INTEGER,
        ENABLED SMALLINT,
        GATEWAY_USAGE_REPORTING SMALLINT,
        GATEWAY_USAGE_MODULE_LOAD_CMD VARCHAR(500),
        GATEWAY_USAGE_EXECUTABLE VARCHAR(255),
        PRIMARY KEY (RESOURCE_ID)
);

CREATE TABLE HOST_ALIAS
(
         RESOURCE_ID VARCHAR(255),
         ALIAS VARCHAR(255),
         PRIMARY KEY(RESOURCE_ID,ALIAS),
         FOREIGN KEY (RESOURCE_ID) REFERENCES COMPUTE_RESOURCE(RESOURCE_ID) ON DELETE CASCADE
);

CREATE TABLE HOST_IPADDRESS
(
         RESOURCE_ID VARCHAR(255),
         IP_ADDRESS VARCHAR(255),
         PRIMARY KEY(RESOURCE_ID,IP_ADDRESS),
         FOREIGN KEY (RESOURCE_ID) REFERENCES COMPUTE_RESOURCE(RESOURCE_ID) ON DELETE CASCADE
);

CREATE TABLE GSISSH_SUBMISSION
(
         SUBMISSION_ID VARCHAR(255),
         RESOURCE_JOB_MANAGER VARCHAR(255),
         SSH_PORT INTEGER,
         INSTALLED_PATH VARCHAR(255),
         MONITOR_MODE VARCHAR(255),
         PRIMARY KEY(SUBMISSION_ID)
);

CREATE TABLE GSISSH_EXPORT
(
         SUBMISSION_ID VARCHAR(255),
         EXPORT VARCHAR(255),
         PRIMARY KEY(SUBMISSION_ID, EXPORT),
         FOREIGN KEY (SUBMISSION_ID) REFERENCES GSISSH_SUBMISSION(SUBMISSION_ID) ON DELETE CASCADE
);



CREATE TABLE GLOBUS_SUBMISSION
(
         SUBMISSION_ID VARCHAR(255),
         RESOURCE_JOB_MANAGER VARCHAR(255),
         SECURITY_PROTOCAL VARCHAR(255),
         PRIMARY KEY(SUBMISSION_ID)
);

CREATE TABLE UNICORE_SUBMISSION
(
         SUBMISSION_ID VARCHAR(255),
         SECURITY_PROTOCAL VARCHAR(255),
         UNICORE_ENDPOINT_URL VARCHAR(255),
         PRIMARY KEY(SUBMISSION_ID)
);

CREATE TABLE UNICORE_DATAMOVEMENT
(
         DATAMOVEMENT_ID VARCHAR(255),
         SECURITY_PROTOCAL VARCHAR(255),
         UNICORE_ENDPOINT_URL VARCHAR(255),
         PRIMARY KEY(DATAMOVEMENT_ID)
);


CREATE TABLE GLOBUS_GK_ENDPOINT
(
         SUBMISSION_ID VARCHAR(255),
         ENDPOINT VARCHAR(255),
         PRIMARY KEY(SUBMISSION_ID, ENDPOINT),
         FOREIGN KEY (SUBMISSION_ID) REFERENCES GLOBUS_SUBMISSION(SUBMISSION_ID) ON DELETE CASCADE
);

CREATE TABLE RESOURCE_JOB_MANAGER
(
        RESOURCE_JOB_MANAGER_ID VARCHAR (255) NOT NULL,
        PUSH_MONITORING_ENDPOINT VARCHAR (255),
        JOB_MANAGER_BIN_PATH VARCHAR (255),
        RESOURCE_JOB_MANAGER_TYPE VARCHAR (255) NOT NULL,
        CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
        PRIMARY KEY (RESOURCE_JOB_MANAGER_ID)
);



CREATE TABLE SSH_JOB_SUBMISSION
(
        RESOURCE_JOB_MANAGER_ID VARCHAR (255) NOT NULL,
        JOB_SUBMISSION_INTERFACE_ID VARCHAR (255) NOT NULL,
        ALTERNATIVE_SSH_HOSTNAME VARCHAR (255),
        SECURITY_PROTOCOL VARCHAR (255) NOT NULL,
        SSH_PORT INTEGER,
        MONITOR_MODE VARCHAR (255),
        CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
        PRIMARY KEY (JOB_SUBMISSION_INTERFACE_ID),
        FOREIGN KEY (RESOURCE_JOB_MANAGER_ID) REFERENCES RESOURCE_JOB_MANAGER(RESOURCE_JOB_MANAGER_ID)
);

CREATE TABLE SCP_DATA_MOVEMENT
(
        QUEUE_DESCRIPTION VARCHAR (255),
        DATA_MOVEMENT_INTERFACE_ID VARCHAR (255) NOT NULL,
        SECURITY_PROTOCOL VARCHAR (255) NOT NULL,
        ALTERNATIVE_SCP_HOSTNAME VARCHAR (255),
        SSH_PORT INTEGER,
        CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
        PRIMARY KEY (DATA_MOVEMENT_INTERFACE_ID)
);

CREATE TABLE GRIDFTP_DATA_MOVEMENT
(
        DATA_MOVEMENT_INTERFACE_ID VARCHAR (255) NOT NULL,
        SECURITY_PROTOCOL VARCHAR (255) NOT NULL,
        CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
        PRIMARY KEY (DATA_MOVEMENT_INTERFACE_ID)
);

CREATE TABLE GRIDFTP_ENDPOINT
(
        ENDPOINT VARCHAR (255) NOT NULL,
        DATA_MOVEMENT_INTERFACE_ID VARCHAR (255) NOT NULL,
        PRIMARY KEY (DATA_MOVEMENT_INTERFACE_ID,ENDPOINT),
        CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
        FOREIGN KEY (DATA_MOVEMENT_INTERFACE_ID) REFERENCES GRIDFTP_DATA_MOVEMENT(DATA_MOVEMENT_INTERFACE_ID) ON DELETE CASCADE
);

--CREATE TABLE JOB_SUBMISSION_PROTOCOL
--(
--         RESOURCE_ID VARCHAR(255),
--         SUBMISSION_ID VARCHAR(255),
--         JOB_TYPE VARCHAR(255),
--         CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
--         UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
--         PRIMARY KEY(RESOURCE_ID,SUBMISSION_ID,JOB_TYPE),
--         FOREIGN KEY (RESOURCE_ID) REFERENCES COMPUTE_RESOURCE(RESOURCE_ID) ON DELETE CASCADE
--);
--
--CREATE TABLE DATA_MOVEMENT_PROTOCOL
--(
--         RESOURCE_ID VARCHAR(255),
--         DATA_MOVE_ID VARCHAR(255),
--         DATA_MOVE_TYPE VARCHAR(255),
--         CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
--         UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
--         PRIMARY KEY(RESOURCE_ID,DATA_MOVE_ID,DATA_MOVE_TYPE),
--         FOREIGN KEY (RESOURCE_ID) REFERENCES COMPUTE_RESOURCE(RESOURCE_ID) ON DELETE CASCADE
--);

CREATE TABLE APPLICATION_MODULE
(
         MODULE_ID VARCHAR(255),
         MODULE_NAME VARCHAR(255),
         MODULE_VERSION VARCHAR(255),
         MODULE_DESC VARCHAR(500),
         GATEWAY_ID VARCHAR (255),
         CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
         UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
         PRIMARY KEY(MODULE_ID)
);

CREATE TABLE APPLICATION_DEPLOYMENT
(
         DEPLOYMENT_ID VARCHAR(255),
         APP_MODULE_ID VARCHAR(255),
         COMPUTE_HOSTID VARCHAR(255),
         EXECUTABLE_PATH VARCHAR(255),
	       PARALLELISM VARCHAR(255),
         APPLICATION_DESC VARCHAR(255),
         CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
         UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
         GATEWAY_ID VARCHAR(255),
         PRIMARY KEY(DEPLOYMENT_ID),
         FOREIGN KEY (COMPUTE_HOSTID) REFERENCES COMPUTE_RESOURCE(RESOURCE_ID) ON DELETE CASCADE,
         FOREIGN KEY (APP_MODULE_ID) REFERENCES APPLICATION_MODULE(MODULE_ID) ON DELETE CASCADE
);

CREATE TABLE MODULE_LOAD_CMD
(
        CMD VARCHAR (255) NOT NULL,
        APP_DEPLOYMENT_ID VARCHAR (255) NOT NULL,
        PRIMARY KEY (APP_DEPLOYMENT_ID,CMD),
        FOREIGN KEY (APP_DEPLOYMENT_ID) REFERENCES APPLICATION_DEPLOYMENT(DEPLOYMENT_ID) ON DELETE CASCADE
);

CREATE TABLE PREJOB_COMMAND
(
         APPDEPLOYMENT_ID VARCHAR(255),
         COMMAND VARCHAR(255),
         PRIMARY KEY(APPDEPLOYMENT_ID, COMMAND),
         FOREIGN KEY (APPDEPLOYMENT_ID) REFERENCES APPLICATION_DEPLOYMENT(DEPLOYMENT_ID) ON DELETE CASCADE
);

CREATE TABLE POSTJOB_COMMAND
(
         APPDEPLOYMENT_ID VARCHAR(255),
         COMMAND VARCHAR(255),
         PRIMARY KEY(APPDEPLOYMENT_ID, COMMAND),
         FOREIGN KEY (APPDEPLOYMENT_ID) REFERENCES APPLICATION_DEPLOYMENT(DEPLOYMENT_ID) ON DELETE CASCADE
);

CREATE TABLE LIBRARY_PREPAND_PATH
(
         DEPLOYMENT_ID VARCHAR(255),
         NAME VARCHAR(255),
         VALUE VARCHAR(255),
         PRIMARY KEY(DEPLOYMENT_ID, NAME),
         FOREIGN KEY (DEPLOYMENT_ID) REFERENCES APPLICATION_DEPLOYMENT(DEPLOYMENT_ID) ON DELETE CASCADE
);

CREATE TABLE LIBRARY_APEND_PATH
(
         DEPLOYMENT_ID VARCHAR(255),
         NAME VARCHAR(255),
         VALUE VARCHAR(255),
         PRIMARY KEY(DEPLOYMENT_ID, NAME),
         FOREIGN KEY (DEPLOYMENT_ID) REFERENCES APPLICATION_DEPLOYMENT(DEPLOYMENT_ID) ON DELETE CASCADE
);

CREATE TABLE APP_ENVIRONMENT
(
         DEPLOYMENT_ID VARCHAR(255),
         NAME VARCHAR(255),
         VALUE VARCHAR(255),
         PRIMARY KEY(DEPLOYMENT_ID, NAME),
         FOREIGN KEY (DEPLOYMENT_ID) REFERENCES APPLICATION_DEPLOYMENT(DEPLOYMENT_ID) ON DELETE CASCADE
);

CREATE TABLE APPLICATION_INTERFACE
(
         INTERFACE_ID VARCHAR(255),
         APPLICATION_NAME VARCHAR(255),
         APPLICATION_DESCRIPTION VARCHAR(500),
         GATEWAY_ID VARCHAR(255),
         ARCHIVE_WORKING_DIRECTORY SMALLINT,
         CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
         UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
         PRIMARY KEY(INTERFACE_ID)
);

CREATE TABLE APP_MODULE_MAPPING
(
         INTERFACE_ID VARCHAR(255),
         MODULE_ID VARCHAR(255),
         PRIMARY KEY(INTERFACE_ID, MODULE_ID),
         FOREIGN KEY (INTERFACE_ID) REFERENCES APPLICATION_INTERFACE(INTERFACE_ID) ON DELETE CASCADE,
         FOREIGN KEY (MODULE_ID) REFERENCES APPLICATION_MODULE(MODULE_ID) ON DELETE CASCADE
);

CREATE TABLE APPLICATION_INPUT
(
         INTERFACE_ID VARCHAR(255),
         INPUT_KEY VARCHAR(255),
         INPUT_VALUE VARCHAR(255),
         DATA_TYPE VARCHAR(255),
         METADATA VARCHAR(255),
         APP_ARGUMENT VARCHAR(255),
         STANDARD_INPUT SMALLINT,
         INPUT_ORDER INTEGER,
         IS_REQUIRED SMALLINT,
         REQUIRED_TO_COMMANDLINE SMALLINT,
         DATA_STAGED SMALLINT,
         USER_FRIENDLY_DESC VARCHAR(255),
         PRIMARY KEY(INTERFACE_ID,INPUT_KEY),
         FOREIGN KEY (INTERFACE_ID) REFERENCES APPLICATION_INTERFACE(INTERFACE_ID) ON DELETE CASCADE
);

CREATE TABLE APPLICATION_OUTPUT
(
         INTERFACE_ID VARCHAR(255),
         OUTPUT_KEY VARCHAR(255),
         OUTPUT_VALUE VARCHAR(255),
         DATA_TYPE VARCHAR(255),
         IS_REQUIRED SMALLINT,
         REQUIRED_TO_COMMANDLINE SMALLINT,
         DATA_MOVEMENT SMALLINT,
         DATA_NAME_LOCATION VARCHAR(255),
         SEARCH_QUERY VARCHAR(255),
         APP_ARGUMENT VARCHAR(255),
         OUTPUT_STREAMING SMALLINT,
         PRIMARY KEY(INTERFACE_ID,OUTPUT_KEY),
         FOREIGN KEY (INTERFACE_ID) REFERENCES APPLICATION_INTERFACE(INTERFACE_ID) ON DELETE CASCADE
);

CREATE TABLE GATEWAY_PROFILE
(
         GATEWAY_ID VARCHAR(255),
         CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
         UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
         CS_TOKEN VARCHAR (255),
         IDENTITY_SERVER_TENANT VARCHAR (255),
         IDENTITY_SERVER_PWD_CRED_TOKEN VARCHAR (255),
         PRIMARY KEY(GATEWAY_ID)
);

CREATE TABLE COMPUTE_RESOURCE_PREFERENCE
(
        GATEWAY_ID VARCHAR(255),
        RESOURCE_ID VARCHAR(255),
        OVERRIDE_BY_AIRAVATA SMALLINT,
        PREFERED_JOB_SUB_PROTOCOL VARCHAR(255),
        PREFERED_DATA_MOVE_PROTOCOL VARCHAR(255),
        PREFERED_BATCH_QUEUE VARCHAR(255),
        SCRATCH_LOCATION VARCHAR(255),
        ALLOCATION_PROJECT_NUMBER VARCHAR(255),
        LOGIN_USERNAME VARCHAR(255),
        RESOURCE_CS_TOKEN VARCHAR(255),
        USAGE_REPORTING_GATEWAY_ID VARCHAR(255),
        QUALITY_OF_SERVICE VARCHAR(255),
        RESERVATION VARCHAR (255),
        RESERVATION_START_TIME timestamp,
        RESERVATION_END_TIME timestamp,
        PRIMARY KEY(GATEWAY_ID,RESOURCE_ID),
        FOREIGN KEY (RESOURCE_ID) REFERENCES COMPUTE_RESOURCE(RESOURCE_ID) ON DELETE CASCADE,
        FOREIGN KEY (GATEWAY_ID) REFERENCES GATEWAY_PROFILE(GATEWAY_ID) ON DELETE CASCADE
);

CREATE TABLE BATCH_QUEUE
(
        COMPUTE_RESOURCE_ID VARCHAR(255) NOT NULL,
        MAX_RUNTIME INTEGER,
        MAX_JOB_IN_QUEUE INTEGER,
        QUEUE_DESCRIPTION VARCHAR(255),
        QUEUE_NAME VARCHAR(255) NOT NULL,
        MAX_PROCESSORS INTEGER,
        MAX_NODES INTEGER,
        MAX_MEMORY INTEGER,
        PRIMARY KEY (COMPUTE_RESOURCE_ID,QUEUE_NAME),
        FOREIGN KEY (COMPUTE_RESOURCE_ID) REFERENCES COMPUTE_RESOURCE(RESOURCE_ID) ON DELETE CASCADE
);

CREATE TABLE COMPUTE_RESOURCE_FILE_SYSTEM
(
        COMPUTE_RESOURCE_ID VARCHAR (255) NOT NULL,
        PATH VARCHAR (255),
        FILE_SYSTEM VARCHAR (255) NOT NULL,
        PRIMARY KEY (COMPUTE_RESOURCE_ID,FILE_SYSTEM),
        FOREIGN KEY (COMPUTE_RESOURCE_ID) REFERENCES COMPUTE_RESOURCE(RESOURCE_ID) ON DELETE CASCADE
  );

CREATE TABLE JOB_SUBMISSION_INTERFACE
(
        JOB_SUBMISSION_INTERFACE_ID VARCHAR (255) NOT NULL,
        COMPUTE_RESOURCE_ID VARCHAR (255) NOT NULL,
        JOB_SUBMISSION_PROTOCOL VARCHAR (255) NOT NULL,
        PRIORITY_ORDER INTEGER,
        CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
        PRIMARY KEY (COMPUTE_RESOURCE_ID,JOB_SUBMISSION_INTERFACE_ID),
        FOREIGN KEY (COMPUTE_RESOURCE_ID) REFERENCES COMPUTE_RESOURCE(RESOURCE_ID) ON DELETE CASCADE
);
 
CREATE TABLE DATA_MOVEMENT_INTERFACE
(
        COMPUTE_RESOURCE_ID VARCHAR (255) NOT NULL,
        DATA_MOVEMENT_PROTOCOL VARCHAR (255) NOT NULL,
        DATA_MOVEMENT_INTERFACE_ID VARCHAR (255) NOT NULL,
        PRIORITY_ORDER INTEGER,
        CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
        PRIMARY KEY (COMPUTE_RESOURCE_ID,DATA_MOVEMENT_INTERFACE_ID),
        FOREIGN KEY (COMPUTE_RESOURCE_ID) REFERENCES COMPUTE_RESOURCE(RESOURCE_ID) ON DELETE CASCADE
);

CREATE TABLE STORAGE_RESOURCE
(
        STORAGE_RESOURCE_ID VARCHAR (255) NOT NULL,
        HOST_NAME VARCHAR (255) NOT NULL,
        DESCRIPTION VARCHAR (255),
        ENABLED SMALLINT ,
        CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
        PRIMARY KEY (STORAGE_RESOURCE_ID)
);

CREATE TABLE STORAGE_INTERFACE
(
        STORAGE_RESOURCE_ID VARCHAR (255) NOT NULL,
        DATA_MOVEMENT_INTERFACE_ID VARCHAR (255) NOT NULL,
        DATA_MOVEMENT_PROTOCOL VARCHAR (255) NOT NULL,
        PRIORITY_ORDER INTEGER,
        CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
        PRIMARY KEY (STORAGE_RESOURCE_ID,DATA_MOVEMENT_INTERFACE_ID),
        FOREIGN KEY (STORAGE_RESOURCE_ID) REFERENCES STORAGE_RESOURCE(STORAGE_RESOURCE_ID) ON DELETE CASCADE
);

CREATE TABLE JOB_MANAGER_COMMAND
(
        RESOURCE_JOB_MANAGER_ID VARCHAR (255) NOT NULL,
        COMMAND_TYPE VARCHAR (255) NOT NULL,
        COMMAND VARCHAR (255),
        PRIMARY KEY (RESOURCE_JOB_MANAGER_ID,COMMAND_TYPE),
        FOREIGN KEY (RESOURCE_JOB_MANAGER_ID) REFERENCES RESOURCE_JOB_MANAGER(RESOURCE_JOB_MANAGER_ID) ON DELETE CASCADE
);

CREATE TABLE PARALLELISM_COMMAND
(
        RESOURCE_JOB_MANAGER_ID VARCHAR (255) NOT NULL,
        COMMAND_TYPE VARCHAR (255) NOT NULL,
        COMMAND VARCHAR (255),
        PRIMARY KEY (RESOURCE_JOB_MANAGER_ID,COMMAND_TYPE),
        FOREIGN KEY (RESOURCE_JOB_MANAGER_ID) REFERENCES RESOURCE_JOB_MANAGER(RESOURCE_JOB_MANAGER_ID) ON DELETE CASCADE
);

CREATE TABLE LOCAL_SUBMISSION
(
        RESOURCE_JOB_MANAGER_ID VARCHAR (255) NOT NULL,
        JOB_SUBMISSION_INTERFACE_ID VARCHAR (255) NOT NULL,
        CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
        PRIMARY KEY (JOB_SUBMISSION_INTERFACE_ID),
        FOREIGN KEY (RESOURCE_JOB_MANAGER_ID) REFERENCES RESOURCE_JOB_MANAGER(RESOURCE_JOB_MANAGER_ID)
);

CREATE TABLE STORAGE_PREFERENCE
(
        GATEWAY_ID VARCHAR(255),
        STORAGE_RESOURCE_ID VARCHAR(255),
        LOGIN_USERNAME VARCHAR(255),
        FS_ROOT_LOCATION VARCHAR(255),
        RESOURCE_CS_TOKEN VARCHAR(255),
        PRIMARY KEY(GATEWAY_ID,STORAGE_RESOURCE_ID),
        FOREIGN KEY (GATEWAY_ID) REFERENCES GATEWAY_PROFILE(GATEWAY_ID) ON DELETE CASCADE
);

CREATE TABLE LOCAL_DATA_MOVEMENT
(
	     DATA_MOVEMENT_INTERFACE_ID VARCHAR (255) NOT NULL,
	     PRIMARY KEY (DATA_MOVEMENT_INTERFACE_ID)
);

CREATE TABLE WORKFLOW
(
        WF_TEMPLATE_ID VARCHAR (255) NOT NULL,
        WF_NAME VARCHAR (255) NOT NULL,
        GRAPH CLOB,
        OWNER VARCHAR(255),
        GATEWAY_ID VARCHAR(255),
        CREATION_TIME TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        UPDATE_TIME TIMESTAMP DEFAULT '0000-00-00 00:00:00',
        IMAGE BLOB,
        PRIMARY KEY (WF_TEMPLATE_ID)
);

CREATE TABLE WORKFLOW_INPUT
(
         WF_TEMPLATE_ID VARCHAR(255),
         INPUT_KEY VARCHAR(255),
         INPUT_VALUE CLOB,
         DATA_TYPE VARCHAR(255),
         METADATA VARCHAR(255),
         APP_ARGUMENT VARCHAR(255),
         STANDARD_INPUT SMALLINT,
         USER_FRIENDLY_DESC VARCHAR(255),
         PRIMARY KEY(WF_TEMPLATE_ID,INPUT_KEY),
         FOREIGN KEY (WF_TEMPLATE_ID) REFERENCES WORKFLOW(WF_TEMPLATE_ID) ON DELETE CASCADE
);

CREATE TABLE WORKFLOW_OUTPUT
(
         WF_TEMPLATE_ID VARCHAR(255),
         OUTPUT_KEY VARCHAR(255),
         OUTPUT_VALUE CLOB,
         DATA_TYPE VARCHAR(255),
         PRIMARY KEY(WF_TEMPLATE_ID,OUTPUT_KEY),
         FOREIGN KEY (WF_TEMPLATE_ID) REFERENCES WORKFLOW(WF_TEMPLATE_ID) ON DELETE CASCADE
);



CREATE TABLE CONFIGURATION
(
        CONFIG_KEY VARCHAR(255),
        CONFIG_VAL VARCHAR(255),
        PRIMARY KEY(CONFIG_KEY, CONFIG_VAL)
);

INSERT INTO CONFIGURATION (CONFIG_KEY, CONFIG_VAL) VALUES('app_catalog_version', '0.16');



