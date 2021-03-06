# Apache Airavata Python SDK
The Apache Airavata Python SDK for  third party clients to  integrate with Airavata middleware


### Folder Structure

 - airavata
      
    Includes thrift stubs generated by a thrift compiler. Mainly contains data model and functions. You may 
              need to import data model packages to integrate with clients. 
              
 - airavata_sdk
    - clients
        
        Includes integration clients, which you want to import and integrate with your code to access airavata middleware.
                
    - samples
        
        Includes set of sample implementation of  integration clients to demonastrate the integration with  airavata middleware
                
    - transport
    
        Includes connection handling classes and connection pool implementations
              

### Before  Integration

  -  Create a virtual environment
                
       ```
       python3 -m venv venv
        ```    
  -  Activate the virtual environment
        
       ```
       source venv/bin/activate
       ```
  -  Install dependencies
            
       ```
       pip install -r requirements.txt
       ```
  -  Create a INI file containing server configuration details. For more information refer to default settings file
            
       [settings.ini](airavata_sdk/transport/settings.ini)
       
### Generating Distribution Archives (Optional)

   You can generate *.tar.gz or .whl distribution and install to any external project. 
   
   - Make sure you have the latest versions of setuptools and wheel installed
    
       ```
       python3 -m pip install --user --upgrade setuptools wheel
       ``` 
   - Now run this command from the same directory where setup.py is located
   
        ```
        python3 setup.py sdist bdist_wheel
        ```
   - This command should output a lot of text and once completed should generate two files in the dist directory
   
        ```
        dist/
            airavata_python_sdk-1.0.0-py2.py3-none-any.whl
            airavata-python-sdk-1.0.0.tar.gz
        ```     

You should be able to install those packages into your project.



### Integrate With Your Clients

   - [api_server_client](airavata_sdk/clients/api_server_client.py)
      - is_user_exists(authz_token, gateway_id, user_name)
      - add_gateway( authz_token, [gateway](airavata/model/workspace/ttypes.py)) 
      - get_all_users_in_gateway( authz_token, gateway_id)
      - update_gateway( authz_token, gateway_id, updated_gateway)
      - get_gateway( authz_token, gateway_id)
      - delete_gateway( authz_token, gateway_id)
      - get_all_gateways( authz_token)
      - is_gateway_exist( authz_token, gateway_id)
      - create_notification( authz_token, [notification](airavata/model/workspace/ttypes.py))
      - update_notification( authz_token, notification)
      - delete_notification( authz_token, gateway_id, notification_id)
      - get_notification( authz_token, gateway_id, notification_id)
      - get_all_notifications( authz_token, gateway_id)
      - generate_and_register_ssh_keys( authz_token, description)
      - register_pwd_credential( authz_token, login_user_name, password, description)
      - delete_ssh_pub_key( authz_token, airavata_cred_store_token)
      - delete_pwd_credential( authz_token, airavata_cred_store_token)
      - create_project( authz_token, gateway_id, [project](airavata/model/workspace/ttypes.py))
      - update_project( authz_token, project_id, updated_project)
      - get_project( authz_token, project_id)
      - delete_project( authz_token, project_id)
      - get_user_projects( authz_token, gateway_id, user_name, limit, offset)
      - search_projects( authz_token, gateway_id, user_name, filters, limit, offset)
      - search_experiments( authz_token, gateway_id, user_name, filters, limit, offset)
      - get_experiment_statistics( authz_token, gateway_id, from_time, to_time, user_name, application_name,
                                  resource_host_name)
      - get_experiments_in_project( authz_token, project_id, limit, offset)
      - get_user_experiments( authz_token, gateway_id, user_name, limit, offset)
      - create_experiment( authz_token, gateway_id, [experiment](airavata/model/experiment/ttypes.py))
      - delete_experiment( authz_token, experiment_id)
      - get_experiment( authz_token, airavata_experiment_id)
      - get_experiment_by_admin( authz_token, airavata_experiment_id)
      - get_detailed_experiment_tree( authz_token, airavata_experiment_id)
      - update_experiment( authz_token, airavata_experiment_id, experiment)
      - update_experiment_configuration( authz_token, airavata_experiment_id, [user_configuration](airavata/model/experiment/ttypes.py))
      - update_resource_scheduling( authz_token, airavata_experiment_id, [resource_scheduling](airavata/model/scheduling/ttypes.py))
      - validate_experiment( authz_token, airavata_experiment_id)
      - launch_experiment( authz_token, airavata_experiment_id, gateway_id)
      - get_experiment_status( authz_token, airavata_experiment_id)
      - get_experiment_outputs( authz_token, airavata_experiment_id)
      - get_intermediate_outputs( authz_token, airavata_experiment_id)
      - get_job_statuses( authz_token, airavata_experiment_id)
      - get_job_details( authz_token, airavata_experiment_id)
      - clone_experiment( authz_token, existing_experiment_id, new_experiment_name, new_experiment_projectId)
      - clone_experiment_by_admin( authz_token, existing_experiment_id, new_experiment_name)
      - terminate_experiment( authz_token, airavata_experiment_id, gateway_id)
      - register_application_module( authz_token, gateway_id, application_module)
      - get_application_module( authz_token, app_module_id)
      - update_application_module( authz_token, app_module_id, [application_module](airavata/model/appcatalog/appdeployment/ttypes.py))
      - get_all_app_modules( authz_token, gateway_id)
      - get_accessible_app_modules( authz_token, gateway_id)
      - delete_application_module( authz_token, app_module_id)
      - register_application_deployment( authz_token, gateway_id, [application_deployment](airavata/model/appcatalog/appdeployment/ttypes.py))
      - get_application_deployment( authz_token, app_deployment_id)
      - update_application_deployment( authz_token, app_deployment_id, application_deployment)
      - delete_application_deployment( authz_token, app_deployment_id)
      - get_all_application_deployments( authz_token, gateway_id):
      - get_accessible_application_deployments( authz_token, gateway_id, [permission_type](airavata/model/sharing/ttypes.py))
      - get_app_module_deployed_resources( authz_token, app_module_id)
      - get_application_deployments_for_app_module_and_group_resource_profile( authz_token, app_module_id,
                                                                              group_resource_profileId)
      - register_application_interface( authz_token, gateway_id, [application_interface](airavata/model/appcatalog/appinterface/ttypes.py))
      - clone_application_interface( authz_token, existing_app_interface_id, new_application_name, gateway_id)
      - get_application_interface( authz_token, app_interface_id)
      - update_application_interface( authz_token, app_interface_id, application_interface)
      - delete_application_interface( authz_token, app_interface_id)
      - get_all_application_interface_names( authz_token, gateway_id)
      - get_all_application_interfaces( authz_token, gateway_id)
      - get_application_inputs( authz_token, app_interface_id)
      - get_application_outputs( authz_token, app_interface_id)
      - get_available_app_interface_compute_resources( authz_token, app_interface_id)
      - register_compute_resource( authz_token, [compute_resource_description](airavata/model/appcatalog/computeresource/ttypes.py))
      - get_compute_resource( authz_token, compute_resource_id)
      - get_all_compute_resource_names( authz_token)
      - update_compute_resource( authz_token, compute_resource_id, compute_resource_description)
      - delete_compute_resource( authz_token, compute_resource_id)
      - register_storage_resource( authz_token, [storage_resource_description](airavata/model/appcatalog/storageresource/ttypes.py))
      - get_storage_resource( authz_token, storage_resource_id)
      - get_all_storage_resource_names( authz_token)
      - update_storage_resource( authz_token, storage_resource_id, storage_resource_description)
      - delete_storage_resource( authz_token, storage_resource_id)
      - add_local_submission_details( authz_token, compute_resource_id, priority_order, [local_submission](airavata/model/appcatalog/computeresource/ttypes.py))
      - update_local_submission_details( authz_token, job_submission_interface_id, local_submission)
      - get_local_job_submission( authz_token, job_submission_id)
      - add_ssh_job_submission_details( authz_token, compute_resource_id, priority_order, [ssh_job_submission](airavata/model/appcatalog/computeresource/ttypes.py))
      - add_ssh_fork_job_submission_details( authz_token, compute_resource_id, priority_order, ssh_job_submission)
      - get_ssh_job_submission( authz_token, job_submission_id)
      - get_unicore_job_submission( authz_token, job_submission_id)
      - add_cloud_job_submission_details( authz_token, compute_resource_id, priority_order, [cloud_submission](airavata/model/appcatalog/computeresource/ttypes.py))
      - get_cloud_job_submission( authz_token, job_submission_id)
      - update_ssh_job_submission_details( authz_token, job_submission_interface_id, [ssh_job_submission](airavata/model/appcatalog/computeresource/ttypes.py))
      - update_cloud_job_submission_details( authz_token, job_submission_interface_id, ssh_job_submission)
      - update_unicore_job_submission_details( authz_token, job_submission_interface_id, [unicore_job_submission](airavata/model/appcatalog/computeresource/ttypes.py))
      - add_local_data_movement_details( authz_token, product_uri, data_move_type, priority_order,
                                        [local_data_movement](airavata/model/data/movement/ttypes.py))
      - update_local_data_movement_details( authz_token, data_movementInterface_id, local_data_movement)
      - get_local_data_movement( authz_token, data_movement_id)
      - add_scp_data_movement_details( authz_token, product_uri, data_move_type, priority_order,[scp_data_movement](airavata/model/data/movement/ttypes.py))
      - update_scp_data_movement_details( authz_token, data_movement_interface_id, scp_data_movement)
      - get_scp_data_movement( authz_token, data_movement_id)
      - add_unicore_data_movement_details( authz_token, product_uri, data_move_type, priority_order,
      - update_unicore_data_movement_details( authz_token, data_movement_interface_id, unicore_data_movement)
      - get_unicore_data_movement( authz_token, data_movement_id)
      - add_grid_ftp_data_movement_details( authz_token, product_uri, data_move_type, priority_order,
                                           grid_ftp_data_movement)
      - update_grid_ftp_data_movement_details( authz_token, data_movement_interface_id, grid_ftp_data_movement)
      - get_grid_ftp_data_movement( authz_token, data_movement_id)
      - change_job_submission_priority( authz_token, job_submission_interface_id, new_priority_order)
      - change_data_movement_priority( authz_token, data_movement_interface_id, new_priority_order)
      - change_job_submission_priorities( authz_token, job_submission_priority_map)
      - change_data_movement_priorities( authz_token, data_movement_priority_map)
      - delete_job_submission_interface( authz_token, compute_resource_id, [job_submission_interface_id](airavata/model/appcatalog/computeresource/ttypes.py))
      - delete_data_movement_interface( authz_token, product_uri, data_movement_interface_id, data_move_type)
      - register_resource_job_manager( authz_token, [resource_job_manager](airavata/model/appcatalog/computeresource/ttypes.py))
      - update_resource_job_manager( authz_token, resource_job_manager_id, updated_resource_job_manager)
      - get_resource_job_manager( authz_token, resource_job_manager_id)
      - delete_resource_job_manager( authz_token, resource_job_manager_id)
      - delete_batch_queue( authz_token, compute_resource_id, queue_name)
      - register_gateway_resource_profile( authz_token, gateway_resource_profile)
      - get_gateway_resource_profile( authz_token, gateway_id)
      - update_gateway_resource_profile( authz_token, gateway_id, gateway_resource_profile)
      - delete_gateway_resource_profile( authz_token, gateway_id)
      - add_gateway_compute_resource_preference( authz_token, gateway_id, compute_resource_id,
                                                compute_resource_preferance)
      - add_gateway_storage_preference( authz_token, gateway_id, storage_resource_id, storage_preference)
      - get_gateway_compute_resource_preference( authz_token, gateway_id, compute_resource_id)
      - get_gateway_storage_preference( authz_token, gateway_id, storage_resourceId)
      - get_all_gateway_compute_resource_preferences( authz_token, gateway_id)
      - get_all_gateway_storage_preferences( authz_token, gateway_id)
      - get_all_gateway_resource_profiles( authz_token)
      - update_gateway_compute_resource_preference( authz_token, gateway_id, compute_resource_id,
                                                   compute_resource_preference)
      - update_gateway_storage_preference( authz_token, gateway_id, storage_id, [storage_preference](airavata/model/appcatalog/gatewayprofile/ttypes.py))
      - delete_gateway_compute_resource_preference( authz_token, gateway_id, compute_resource_id)
      - delete_gateway_storage_preference( authz_token, gateway_id, storage_id)
      - get_ssh_account_provisioners( authz_token)
      - does_user_have_ssh_account( authz_token, compute_resource_id, user_id)
      - is_ssh_setup_complete_for_user_compute_resource_preference( authz_token, compute_resource_id,
                                                                   airavata_cred_store_token):
      - setup_user_compute_resource_preferences_for_ssh( authz_token, compute_resource_id, user_id,
                                                        airavata_cred_store_token)
      - register_user_resource_profile( authz_token, user_resource_profile)
      - is_user_resource_profile_exists( authz_token, user_id, gateway_id)
      - get_user_resource_profile( authz_token, user_id, gateway_id)
      - update_user_resource_profile( authz_token, user_id, gateway_id, user_resource_profile):
      - delete_user_resource_profile( authz_token, user_id, gateway_id)
      - add_user_compute_resource_preference( authz_token, user_id, gateway_id, user_compute_resource_id,
                                             user_compute_resource_preference)
      - add_user_storage_preference( authz_token, user_id, gateway_id, user_storage_resource_id,
                                    user_storage_preference)
      - get_user_compute_resource_preference( authz_token, user_id, gateway_id, user_compute_resource_id):
      - get_user_storage_preference( authz_token, user_id, gateway_id, user_storage_resource_id)
      - get_all_user_compute_resource_preferences( authz_token, user_id, gateway_id)
      - get_all_user_storage_preferences( authz_token, user_id, gateway_id)
      - get_all_user_resource_profiles( authz_token)
      - update_user_compute_resource_preference( authz_token, user_id, gateway_id, user_compute_resourceId,
                                                user_compute_resource_preference)
      - update_user_storage_preference( authz_token, user_id, gateway_id, user_storage_id,
                                       user_storage_preference)
      - delete_user_compute_resource_preference( authz_token, user_id, gateway_id, user_compute_resource_id)
      - delete_user_storage_preference( authz_token, user_id, gateway_id, user_storage_id)
      - get_latest_queue_statuses( authz_token)
      - register_data_product( authz_token, [data_product_model](airavata/model/data/replica/ttypes.py))
      - get_data_product( authz_token, data_product_uri)
      - register_replica_location( authz_token, [replica_location_model](airavata/model/data/replica/ttypes.py))
      - get_parent_data_product( authz_token, product_uri)
      - get_child_data_products( authz_token, product_uri)
      - share_resource_with_users( authz_token, resource_id, user_permission_list)
      - share_resource_with_groups( authz_token, resource_id, group_permission_list)
      - revoke_sharing_of_resource_from_users( authz_token, resource_id, user_permission_list)
      - revoke_sharing_of_resource_from_groups( authz_token, resource_id, group_permission_list)
      - get_all_accessible_users( authz_token, resource_id, permission_type)
      - get_all_accessible_groups( authz_token, resource_id, permission_type)
      - get_all_directly_accessible_users( authz_token, resource_id, permission_type)
      - get_all_directly_accessible_groups( authz_token, resource_id, permission_type)
      - user_has_access( authz_token, resource_id, [permission_type](airavata/model/sharing/ttypes.py))
      - create_group_resource_profile( authz_token, group_resource_profile)
      - update_group_resource_profile( authz_token, group_resource_profile)
      - get_group_resource_profile( authz_token, group_resource_profile_id)
      - remove_group_resource_profile( authz_token, group_resource_profile_id)
      - get_group_resource_list( authz_token, gateway_id)
      - remove_group_compute_prefs( authz_token, compute_resource_id, group_resource_profile_id)
      - remove_group_compute_resource_policy( authz_token, resource_policy_id)
      - remove_group_batch_queue_resource_policy( authz_token, resource_policy_id)
      - get_group_compute_resource_preference( authz_token, compute_resource_id, group_resource_profile_id)
      - get_group_compute_resource_policy( authz_token, resource_policy_id)
      - get_batch_queue_resource_policy( authz_token, resource_policy_id)
      - get_group_compute_resource_pref_list( authz_token, group_resource_profile_id)
      - get_group_batch_queue_resource_policy_list( authz_token, group_resource_profile_id)
      - get_group_compute_resource_policy_list( authz_token, group_resource_profile_id)
      - get_gateway_groups( authz_token)
      - get_parser( authz_token, parser_id, gateway_id)
      - save_parser( authz_token, parser)
      - list_all_parsers( authz_token, gateway_id)
      - remove_parser( authz_token, parser_id, gateway_id)
      - get_parsing_template( authz_token, template_id, gateway_id)
      - get_parsing_templates_for_experiment( authz_token, experiment_id, gateway_id)
      - save_parsing_template( authz_token, parsing_template)
      - remove_parsing_template( authz_token, template_id, gateway_id)
      - list_all_parsing_templates( authz_token, gateway_id)
      
   Sample implementations can be found at [api_server_client_samples](airavata_sdk/samples/api_server_client_samples.py)
      
   -  [group_manager_client](airavata_sdk/clients/group_manager_client.py)
   
      - create_group( authz_token, [group_model](airavata/model/group/ttypes.py))
      - update_group( authz_token, group_model)
      - delete_group( authz_token, group_id, owner_id)
      - get_group( authz_token, group_id)
      - get_groups( authz_token)
      - get_all_groups_user_belongs( authz_token, user_name)
      - add_users_to_group( authz_token, user_ids, group_id)
      - remove_users_from_group( authz_token, user_ids, group_id)
      - transfer_group_ownership( authz_token, group_id, new_owner_id)
      - add_group_admins( authz_token, group_id, admin_ids)
      - remove_group_admins( authz_token, group_id, admin_ids)
      - has_admin_access( authz_token, group_id, admin_id)
      - has_owner_access( authz_token, group_id, owner_id)
      
   Sample implementations can be found at [group_manager_client_samples](airavata_sdk/samples/group_manager_client_samples.py)
      
   -   [iam_admin_client](airavata_sdk/clients/iam_admin_client.py)
      
       - set_up_gateway( authz_token, gateway)
       - is_username_available( authz_token, username)
       - register_user( authz_token, username, email_address, first_name, last_name, new_password)
       - enable_user( authz_token, username)
       - is_user_enabled( authz_token, username)
       - is_user_exist( authz_token, username)
       - get_user( authz_token, username)
       - get_users( authz_token, offset, limit, search)
       - reset_user_password( authz_token, username, new_password)
       - find_users( authz_token, email, user_id)
       - update_user_profile( authz_token, user_details)
       - delete_user( authz_token, username)
       - add_role_to_user( authz_token, username, role_name)
       - remove_role_from_user( authz_token, username, role_name)
       -  get_users_with_role( authz_token, role_name)
   
   Sample implementations can be found at [iam_admin_client_samples](airavata_sdk/samples/iam_admin_client_samples.py)
    
    
   - [sharing_registry_client](airavata_sdk/clients/sharing_registry_client.py)   
       
       - create_domain([domain](airavata/model/sharing/ttypes.py)) 
       - update_domain( domain)
       - is_domain_exists( domain_id)
       - delete_domain( domain_id)
       - get_domain( domain_id)
       - get_domains( offset, limit)
       - create_user( user)
       - updated_user( user)
       - is_user_exists( domain_id, user_id)
       - delete_user( domain_id, user_id)
       - get_user( domain_id, user_id)
       - get_users( domain_id, offset, limit)
       - is_group_exists( domain_id, group_id)
       - delete_group( domain_id, group_id)
       - get_group( domain_id, group_id)
       - get_groups( domain_id, offset, limit)
       - add_users_to_group( domain_id, user_ids, group_id)
       - remove_users_from_group( domain_id, user_ids, group_id)
       - transfer_group_ownership( domain_id, group_id, new_owner_id)
       - add_group_admins( domain_id, group_id, admin_ids)
       - remove_group_admins( domain_id, group_id, admin_ids)
       - has_admin_access( domain_id, group_id, admin_id)
       - has_owner_access( domain_id, group_id, owner_id)
       - get_group_members_of_type_user( domain_id, group_id, offset, limit)
       - get_group_members_of_type_group( domain_id, group_id, offset, limit)
       - add_child_groups_to_parent_group( domain_id, child_ids, group_id)
       - remove_child_group_from_parent_group( domain_id, child_id, group_id)
       - get_all_member_groups_for_user( domain_id, user_id)
       - create_entity_type( entity_type)
       - update_entity_type( entity_type)
       - is_entity_type_exists( domain_id, entity_type_id)
       - delete_entity_type( domain_id, entity_type_id)
       - get_entity_type( domain_id, entity_type_id)
       - get_entity_types( domain_id, offset, limit)
       - create_entity( [entity](airavata/model/sharing/ttypes.py))
       - update_entity( entity)
       - is_entity_exists( domain_id, entity_id)
       - delete_entity( domain_id, entity_id)
       - get_entity( domain_id, entity_id)
       - search_entities( domain_id, user_id, filters, offset, limit)
       - get_list_of_shared_users( domain_id, entity_id, permission_type_id)
       - get_list_of_directly_shared_users( domain_id, entity_id, permission_type_id)
       - get_list_of_shared_groups( domain_id, entity_id, permission_type_id)
       - get_list_of_directly_shared_groups( domain_id, entity_id, permission_type_id)
       - create_permission_type( permission_type)
       - update_permission_type( permission_type)
       - is_permission_exists( domain_id, permission_id)
       - delete_permission_type( domain_id, permission_type_id)
       - get_permission_type( domain_id, permission_type_id)
       - get_permission_types( domain_id, offset, limit)
       - share_entity_with_users( domain_id, entity_id, user_list, permission_type_id, cascade_permission)
       - revoke_entity_sharing_from_users( domain_id, entity_id, user_list, permission_type_id)
       - share_entity_with_groups( domain_id, entity_id, group_list, permission_type_id, cascade_permission)
       - revoke_entity_sharing_from_groups( domain_id, entity_id, group_list, permission_type_id)
       - user_has_access( domain_id, user_id, entity_id, permission_type_id) 
       
   Sample implementations can be found at [sharing_registry_client_samples](airavata_sdk/samples/sharing_registry_client_samples.py)
       
       
       
   - [tenant_profile_client](airavata_sdk/clients/tenant_profile_client.py)
   
       - add_gateway( authz_token, gateway)
       - update_gateway( authz_token, updated_gateway)
       - get_gateway( authz_token, airavata_internal_gateway_id)
       - delete_gateway( authz_token, airavata_internal_gateway_id, gateway_id)
       - get_all_gateways( authz_token)
       - is_gateway_exist( authz_token, gateway_id)
       - get_all_gateways_for_user( authz_token, requester_username)
   
   Sample implementations can be found at [tenant_profile_client_samples](airavata_sdk/samples/tenant_profile_client_samples.py)    
       
       
   - [user_profile_client](airavata_sdk/clients/user_profile_client.py)
       
       - initialize_user_profile( authz_token)
       - add_user_profile( authz_token, [user_profile](airavata/model/user/ttypes.py))
       - update_user_profile( authz_token, user_profile)
       -  get_user_profile_by_id( authz_token, user_id, gateway_id)
       - delete_user_profile( authz_token, user_id, gateway_id)
       - get_all_user_profiles_in_gateway( authz_token, gateway_id, offset, limit)
       - does_user_exist( authz_token, user_id, gateway_id)
       
   Sample implementations can be found at [user_profile_client_samples](airavata_sdk/samples/user_profile_client_samples.py)
