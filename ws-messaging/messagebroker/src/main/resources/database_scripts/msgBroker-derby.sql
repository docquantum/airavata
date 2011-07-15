CREATE TABLE SUBSCRIPTION (
                SUBSCRIPTIONID VARCHAR(200) NOT NULL DEFAULT '',          
                TOPICS VARCHAR(255) DEFAULT '',                               
                XPATH VARCHAR(200) DEFAULT '',                       
                CONSUMERADDRESS VARCHAR(100) DEFAULT '',                      
                REFERENCEPROPERTIES BLOB,
                CONTENT BLOB,                                                     
                WSRM INTEGER NOT NULL DEFAULT 0 ,                                  
                CREATIONTIME TIMESTAMP NOT NULL  
              );
CREATE TABLE SPECIALSUBSCRIPTION (                              
                       SUBSCRIPTIONID VARCHAR(200) NOT NULL DEFAULT '',              
                       TOPICS VARCHAR(255) DEFAULT '',                               
                       XPATH VARCHAR(200) DEFAULT '',                                
                       CONSUMERADDRESS VARCHAR(100) DEFAULT '',                      
                       REFERENCEPROPERTIES BLOB,                                     
                       CONTENT BLOB,                                                     
                       WSRM INTEGER NOT NULL DEFAULT 0,                         
                       CREATIONTIME TIMESTAMP NOT NULL 
                     );               

	
CREATE TABLE DISQ (                       
          ID INTEGER GENERATED ALWAYS AS IDENTITY,  
          TRACKID VARCHAR(100) DEFAULT NULL,      
          MESSAGE BLOB,                           
          STATUS INTEGER  DEFAULT NULL,    
          TOPIC VARCHAR(255) DEFAULT '',     
          PRIMARY KEY  (ID)                       
        );	
	
CREATE TABLE MAXIDTABLE(
	MAXID INTEGER
	);
	
CREATE TABLE MINIDTABLE(
	MINID INTEGER
	);
	
