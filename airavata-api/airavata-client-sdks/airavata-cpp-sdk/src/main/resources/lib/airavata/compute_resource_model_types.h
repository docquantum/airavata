/**
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef compute_resource_model_TYPES_H
#define compute_resource_model_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "airavata_commons_types.h"
#include "parallelism_model_types.h"
#include "data_movement_models_types.h"


namespace apache { namespace airavata { namespace model { namespace appcatalog { namespace computeresource {

struct ResourceJobManagerType {
  enum type {
    FORK = 0,
    PBS = 1,
    SLURM = 2,
    LSF = 3,
    UGE = 4,
    CLOUD = 5
  };
};

extern const std::map<int, const char*> _ResourceJobManagerType_VALUES_TO_NAMES;

struct JobManagerCommand {
  enum type {
    SUBMISSION = 0,
    JOB_MONITORING = 1,
    DELETION = 2,
    CHECK_JOB = 3,
    SHOW_QUEUE = 4,
    SHOW_RESERVATION = 5,
    SHOW_START = 6
  };
};

extern const std::map<int, const char*> _JobManagerCommand_VALUES_TO_NAMES;

struct FileSystems {
  enum type {
    HOME = 0,
    WORK = 1,
    LOCALTMP = 2,
    SCRATCH = 3,
    ARCHIVE = 4
  };
};

extern const std::map<int, const char*> _FileSystems_VALUES_TO_NAMES;

struct JobSubmissionProtocol {
  enum type {
    LOCAL = 0,
    SSH = 1,
    GLOBUS = 2,
    UNICORE = 3,
    CLOUD = 4,
    SSH_FORK = 5,
    LOCAL_FORK = 6
  };
};

extern const std::map<int, const char*> _JobSubmissionProtocol_VALUES_TO_NAMES;

struct MonitorMode {
  enum type {
    POLL_JOB_MANAGER = 0,
    CLOUD_JOB_MONITOR = 1,
    JOB_EMAIL_NOTIFICATION_MONITOR = 2,
    XSEDE_AMQP_SUBSCRIBE = 3,
    FORK = 4,
    LOCAL = 5
  };
};

extern const std::map<int, const char*> _MonitorMode_VALUES_TO_NAMES;

struct DMType {
  enum type {
    COMPUTE_RESOURCE = 0,
    STORAGE_RESOURCE = 1
  };
};

extern const std::map<int, const char*> _DMType_VALUES_TO_NAMES;

struct ProviderName {
  enum type {
    EC2 = 0,
    AWSEC2 = 1,
    RACKSPACE = 2
  };
};

extern const std::map<int, const char*> _ProviderName_VALUES_TO_NAMES;

class ResourceJobManager;

class BatchQueue;

class LOCALSubmission;

class SSHJobSubmission;

class GlobusJobSubmission;

class UnicoreJobSubmission;

class CloudJobSubmission;

class JobSubmissionInterface;

class ComputeResourceDescription;

typedef struct _ResourceJobManager__isset {
  _ResourceJobManager__isset() : pushMonitoringEndpoint(false), jobManagerBinPath(false), jobManagerCommands(false), parallelismPrefix(false) {}
  bool pushMonitoringEndpoint :1;
  bool jobManagerBinPath :1;
  bool jobManagerCommands :1;
  bool parallelismPrefix :1;
} _ResourceJobManager__isset;

class ResourceJobManager {
 public:

  ResourceJobManager(const ResourceJobManager&);
  ResourceJobManager& operator=(const ResourceJobManager&);
  ResourceJobManager() : resourceJobManagerId("DO_NOT_SET_AT_CLIENTS"), resourceJobManagerType((ResourceJobManagerType::type)0), pushMonitoringEndpoint(), jobManagerBinPath() {
  }

  virtual ~ResourceJobManager() throw();
  std::string resourceJobManagerId;
  ResourceJobManagerType::type resourceJobManagerType;
  std::string pushMonitoringEndpoint;
  std::string jobManagerBinPath;
  std::map<JobManagerCommand::type, std::string>  jobManagerCommands;
  std::map< ::apache::airavata::model::appcatalog::parallelism::ApplicationParallelismType::type, std::string>  parallelismPrefix;

  _ResourceJobManager__isset __isset;

  void __set_resourceJobManagerId(const std::string& val);

  void __set_resourceJobManagerType(const ResourceJobManagerType::type val);

  void __set_pushMonitoringEndpoint(const std::string& val);

  void __set_jobManagerBinPath(const std::string& val);

  void __set_jobManagerCommands(const std::map<JobManagerCommand::type, std::string> & val);

  void __set_parallelismPrefix(const std::map< ::apache::airavata::model::appcatalog::parallelism::ApplicationParallelismType::type, std::string> & val);

  bool operator == (const ResourceJobManager & rhs) const
  {
    if (!(resourceJobManagerId == rhs.resourceJobManagerId))
      return false;
    if (!(resourceJobManagerType == rhs.resourceJobManagerType))
      return false;
    if (__isset.pushMonitoringEndpoint != rhs.__isset.pushMonitoringEndpoint)
      return false;
    else if (__isset.pushMonitoringEndpoint && !(pushMonitoringEndpoint == rhs.pushMonitoringEndpoint))
      return false;
    if (__isset.jobManagerBinPath != rhs.__isset.jobManagerBinPath)
      return false;
    else if (__isset.jobManagerBinPath && !(jobManagerBinPath == rhs.jobManagerBinPath))
      return false;
    if (__isset.jobManagerCommands != rhs.__isset.jobManagerCommands)
      return false;
    else if (__isset.jobManagerCommands && !(jobManagerCommands == rhs.jobManagerCommands))
      return false;
    if (__isset.parallelismPrefix != rhs.__isset.parallelismPrefix)
      return false;
    else if (__isset.parallelismPrefix && !(parallelismPrefix == rhs.parallelismPrefix))
      return false;
    return true;
  }
  bool operator != (const ResourceJobManager &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ResourceJobManager & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ResourceJobManager &a, ResourceJobManager &b);

inline std::ostream& operator<<(std::ostream& out, const ResourceJobManager& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _BatchQueue__isset {
  _BatchQueue__isset() : queueDescription(false), maxRunTime(false), maxNodes(false), maxProcessors(false), maxJobsInQueue(false), maxMemory(false), cpuPerNode(false), defaultNodeCount(false), defaultCPUCount(false), isDefaultQueue(false) {}
  bool queueDescription :1;
  bool maxRunTime :1;
  bool maxNodes :1;
  bool maxProcessors :1;
  bool maxJobsInQueue :1;
  bool maxMemory :1;
  bool cpuPerNode :1;
  bool defaultNodeCount :1;
  bool defaultCPUCount :1;
  bool isDefaultQueue :1;
} _BatchQueue__isset;

class BatchQueue {
 public:

  BatchQueue(const BatchQueue&);
  BatchQueue& operator=(const BatchQueue&);
  BatchQueue() : queueName(), queueDescription(), maxRunTime(0), maxNodes(0), maxProcessors(0), maxJobsInQueue(0), maxMemory(0), cpuPerNode(0), defaultNodeCount(0), defaultCPUCount(0), isDefaultQueue(0) {
  }

  virtual ~BatchQueue() throw();
  std::string queueName;
  std::string queueDescription;
  int32_t maxRunTime;
  int32_t maxNodes;
  int32_t maxProcessors;
  int32_t maxJobsInQueue;
  int32_t maxMemory;
  int32_t cpuPerNode;
  int32_t defaultNodeCount;
  int32_t defaultCPUCount;
  bool isDefaultQueue;

  _BatchQueue__isset __isset;

  void __set_queueName(const std::string& val);

  void __set_queueDescription(const std::string& val);

  void __set_maxRunTime(const int32_t val);

  void __set_maxNodes(const int32_t val);

  void __set_maxProcessors(const int32_t val);

  void __set_maxJobsInQueue(const int32_t val);

  void __set_maxMemory(const int32_t val);

  void __set_cpuPerNode(const int32_t val);

  void __set_defaultNodeCount(const int32_t val);

  void __set_defaultCPUCount(const int32_t val);

  void __set_isDefaultQueue(const bool val);

  bool operator == (const BatchQueue & rhs) const
  {
    if (!(queueName == rhs.queueName))
      return false;
    if (__isset.queueDescription != rhs.__isset.queueDescription)
      return false;
    else if (__isset.queueDescription && !(queueDescription == rhs.queueDescription))
      return false;
    if (__isset.maxRunTime != rhs.__isset.maxRunTime)
      return false;
    else if (__isset.maxRunTime && !(maxRunTime == rhs.maxRunTime))
      return false;
    if (__isset.maxNodes != rhs.__isset.maxNodes)
      return false;
    else if (__isset.maxNodes && !(maxNodes == rhs.maxNodes))
      return false;
    if (__isset.maxProcessors != rhs.__isset.maxProcessors)
      return false;
    else if (__isset.maxProcessors && !(maxProcessors == rhs.maxProcessors))
      return false;
    if (__isset.maxJobsInQueue != rhs.__isset.maxJobsInQueue)
      return false;
    else if (__isset.maxJobsInQueue && !(maxJobsInQueue == rhs.maxJobsInQueue))
      return false;
    if (__isset.maxMemory != rhs.__isset.maxMemory)
      return false;
    else if (__isset.maxMemory && !(maxMemory == rhs.maxMemory))
      return false;
    if (__isset.cpuPerNode != rhs.__isset.cpuPerNode)
      return false;
    else if (__isset.cpuPerNode && !(cpuPerNode == rhs.cpuPerNode))
      return false;
    if (__isset.defaultNodeCount != rhs.__isset.defaultNodeCount)
      return false;
    else if (__isset.defaultNodeCount && !(defaultNodeCount == rhs.defaultNodeCount))
      return false;
    if (__isset.defaultCPUCount != rhs.__isset.defaultCPUCount)
      return false;
    else if (__isset.defaultCPUCount && !(defaultCPUCount == rhs.defaultCPUCount))
      return false;
    if (__isset.isDefaultQueue != rhs.__isset.isDefaultQueue)
      return false;
    else if (__isset.isDefaultQueue && !(isDefaultQueue == rhs.isDefaultQueue))
      return false;
    return true;
  }
  bool operator != (const BatchQueue &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const BatchQueue & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(BatchQueue &a, BatchQueue &b);

inline std::ostream& operator<<(std::ostream& out, const BatchQueue& obj)
{
  obj.printTo(out);
  return out;
}


class LOCALSubmission {
 public:

  LOCALSubmission(const LOCALSubmission&);
  LOCALSubmission& operator=(const LOCALSubmission&);
  LOCALSubmission() : jobSubmissionInterfaceId("DO_NOT_SET_AT_CLIENTS"), securityProtocol(( ::apache::airavata::model::data::movement::SecurityProtocol::type)0) {
  }

  virtual ~LOCALSubmission() throw();
  std::string jobSubmissionInterfaceId;
  ResourceJobManager resourceJobManager;
   ::apache::airavata::model::data::movement::SecurityProtocol::type securityProtocol;

  void __set_jobSubmissionInterfaceId(const std::string& val);

  void __set_resourceJobManager(const ResourceJobManager& val);

  void __set_securityProtocol(const  ::apache::airavata::model::data::movement::SecurityProtocol::type val);

  bool operator == (const LOCALSubmission & rhs) const
  {
    if (!(jobSubmissionInterfaceId == rhs.jobSubmissionInterfaceId))
      return false;
    if (!(resourceJobManager == rhs.resourceJobManager))
      return false;
    if (!(securityProtocol == rhs.securityProtocol))
      return false;
    return true;
  }
  bool operator != (const LOCALSubmission &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LOCALSubmission & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(LOCALSubmission &a, LOCALSubmission &b);

inline std::ostream& operator<<(std::ostream& out, const LOCALSubmission& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _SSHJobSubmission__isset {
  _SSHJobSubmission__isset() : alternativeSSHHostName(false), sshPort(true), monitorMode(false), batchQueueEmailSenders(false) {}
  bool alternativeSSHHostName :1;
  bool sshPort :1;
  bool monitorMode :1;
  bool batchQueueEmailSenders :1;
} _SSHJobSubmission__isset;

class SSHJobSubmission {
 public:

  SSHJobSubmission(const SSHJobSubmission&);
  SSHJobSubmission& operator=(const SSHJobSubmission&);
  SSHJobSubmission() : jobSubmissionInterfaceId("DO_NOT_SET_AT_CLIENTS"), securityProtocol(( ::apache::airavata::model::data::movement::SecurityProtocol::type)0), alternativeSSHHostName(), sshPort(22), monitorMode((MonitorMode::type)0) {
  }

  virtual ~SSHJobSubmission() throw();
  std::string jobSubmissionInterfaceId;
   ::apache::airavata::model::data::movement::SecurityProtocol::type securityProtocol;
  ResourceJobManager resourceJobManager;
  std::string alternativeSSHHostName;
  int32_t sshPort;
  MonitorMode::type monitorMode;
  std::vector<std::string>  batchQueueEmailSenders;

  _SSHJobSubmission__isset __isset;

  void __set_jobSubmissionInterfaceId(const std::string& val);

  void __set_securityProtocol(const  ::apache::airavata::model::data::movement::SecurityProtocol::type val);

  void __set_resourceJobManager(const ResourceJobManager& val);

  void __set_alternativeSSHHostName(const std::string& val);

  void __set_sshPort(const int32_t val);

  void __set_monitorMode(const MonitorMode::type val);

  void __set_batchQueueEmailSenders(const std::vector<std::string> & val);

  bool operator == (const SSHJobSubmission & rhs) const
  {
    if (!(jobSubmissionInterfaceId == rhs.jobSubmissionInterfaceId))
      return false;
    if (!(securityProtocol == rhs.securityProtocol))
      return false;
    if (!(resourceJobManager == rhs.resourceJobManager))
      return false;
    if (__isset.alternativeSSHHostName != rhs.__isset.alternativeSSHHostName)
      return false;
    else if (__isset.alternativeSSHHostName && !(alternativeSSHHostName == rhs.alternativeSSHHostName))
      return false;
    if (__isset.sshPort != rhs.__isset.sshPort)
      return false;
    else if (__isset.sshPort && !(sshPort == rhs.sshPort))
      return false;
    if (__isset.monitorMode != rhs.__isset.monitorMode)
      return false;
    else if (__isset.monitorMode && !(monitorMode == rhs.monitorMode))
      return false;
    if (__isset.batchQueueEmailSenders != rhs.__isset.batchQueueEmailSenders)
      return false;
    else if (__isset.batchQueueEmailSenders && !(batchQueueEmailSenders == rhs.batchQueueEmailSenders))
      return false;
    return true;
  }
  bool operator != (const SSHJobSubmission &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SSHJobSubmission & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(SSHJobSubmission &a, SSHJobSubmission &b);

inline std::ostream& operator<<(std::ostream& out, const SSHJobSubmission& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _GlobusJobSubmission__isset {
  _GlobusJobSubmission__isset() : globusGateKeeperEndPoint(false) {}
  bool globusGateKeeperEndPoint :1;
} _GlobusJobSubmission__isset;

class GlobusJobSubmission {
 public:

  GlobusJobSubmission(const GlobusJobSubmission&);
  GlobusJobSubmission& operator=(const GlobusJobSubmission&);
  GlobusJobSubmission() : jobSubmissionInterfaceId("DO_NOT_SET_AT_CLIENTS"), securityProtocol(( ::apache::airavata::model::data::movement::SecurityProtocol::type)0) {
  }

  virtual ~GlobusJobSubmission() throw();
  std::string jobSubmissionInterfaceId;
   ::apache::airavata::model::data::movement::SecurityProtocol::type securityProtocol;
  std::vector<std::string>  globusGateKeeperEndPoint;

  _GlobusJobSubmission__isset __isset;

  void __set_jobSubmissionInterfaceId(const std::string& val);

  void __set_securityProtocol(const  ::apache::airavata::model::data::movement::SecurityProtocol::type val);

  void __set_globusGateKeeperEndPoint(const std::vector<std::string> & val);

  bool operator == (const GlobusJobSubmission & rhs) const
  {
    if (!(jobSubmissionInterfaceId == rhs.jobSubmissionInterfaceId))
      return false;
    if (!(securityProtocol == rhs.securityProtocol))
      return false;
    if (__isset.globusGateKeeperEndPoint != rhs.__isset.globusGateKeeperEndPoint)
      return false;
    else if (__isset.globusGateKeeperEndPoint && !(globusGateKeeperEndPoint == rhs.globusGateKeeperEndPoint))
      return false;
    return true;
  }
  bool operator != (const GlobusJobSubmission &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const GlobusJobSubmission & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(GlobusJobSubmission &a, GlobusJobSubmission &b);

inline std::ostream& operator<<(std::ostream& out, const GlobusJobSubmission& obj)
{
  obj.printTo(out);
  return out;
}


class UnicoreJobSubmission {
 public:

  UnicoreJobSubmission(const UnicoreJobSubmission&);
  UnicoreJobSubmission& operator=(const UnicoreJobSubmission&);
  UnicoreJobSubmission() : jobSubmissionInterfaceId("DO_NOT_SET_AT_CLIENTS"), securityProtocol(( ::apache::airavata::model::data::movement::SecurityProtocol::type)0), unicoreEndPointURL() {
  }

  virtual ~UnicoreJobSubmission() throw();
  std::string jobSubmissionInterfaceId;
   ::apache::airavata::model::data::movement::SecurityProtocol::type securityProtocol;
  std::string unicoreEndPointURL;

  void __set_jobSubmissionInterfaceId(const std::string& val);

  void __set_securityProtocol(const  ::apache::airavata::model::data::movement::SecurityProtocol::type val);

  void __set_unicoreEndPointURL(const std::string& val);

  bool operator == (const UnicoreJobSubmission & rhs) const
  {
    if (!(jobSubmissionInterfaceId == rhs.jobSubmissionInterfaceId))
      return false;
    if (!(securityProtocol == rhs.securityProtocol))
      return false;
    if (!(unicoreEndPointURL == rhs.unicoreEndPointURL))
      return false;
    return true;
  }
  bool operator != (const UnicoreJobSubmission &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UnicoreJobSubmission & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(UnicoreJobSubmission &a, UnicoreJobSubmission &b);

inline std::ostream& operator<<(std::ostream& out, const UnicoreJobSubmission& obj)
{
  obj.printTo(out);
  return out;
}


class CloudJobSubmission {
 public:

  CloudJobSubmission(const CloudJobSubmission&);
  CloudJobSubmission& operator=(const CloudJobSubmission&);
  CloudJobSubmission() : jobSubmissionInterfaceId("DO_NOT_SET_AT_CLIENTS"), securityProtocol(( ::apache::airavata::model::data::movement::SecurityProtocol::type)0), jobManagerType((ResourceJobManagerType::type)0), nodeId(), executableType(), providerName((ProviderName::type)0), userAccountName() {
  }

  virtual ~CloudJobSubmission() throw();
  std::string jobSubmissionInterfaceId;
   ::apache::airavata::model::data::movement::SecurityProtocol::type securityProtocol;
  ResourceJobManagerType::type jobManagerType;
  std::string nodeId;
  std::string executableType;
  ProviderName::type providerName;
  std::string userAccountName;

  void __set_jobSubmissionInterfaceId(const std::string& val);

  void __set_securityProtocol(const  ::apache::airavata::model::data::movement::SecurityProtocol::type val);

  void __set_jobManagerType(const ResourceJobManagerType::type val);

  void __set_nodeId(const std::string& val);

  void __set_executableType(const std::string& val);

  void __set_providerName(const ProviderName::type val);

  void __set_userAccountName(const std::string& val);

  bool operator == (const CloudJobSubmission & rhs) const
  {
    if (!(jobSubmissionInterfaceId == rhs.jobSubmissionInterfaceId))
      return false;
    if (!(securityProtocol == rhs.securityProtocol))
      return false;
    if (!(jobManagerType == rhs.jobManagerType))
      return false;
    if (!(nodeId == rhs.nodeId))
      return false;
    if (!(executableType == rhs.executableType))
      return false;
    if (!(providerName == rhs.providerName))
      return false;
    if (!(userAccountName == rhs.userAccountName))
      return false;
    return true;
  }
  bool operator != (const CloudJobSubmission &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CloudJobSubmission & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(CloudJobSubmission &a, CloudJobSubmission &b);

inline std::ostream& operator<<(std::ostream& out, const CloudJobSubmission& obj)
{
  obj.printTo(out);
  return out;
}


class JobSubmissionInterface {
 public:

  JobSubmissionInterface(const JobSubmissionInterface&);
  JobSubmissionInterface& operator=(const JobSubmissionInterface&);
  JobSubmissionInterface() : jobSubmissionInterfaceId(), jobSubmissionProtocol((JobSubmissionProtocol::type)0), priorityOrder(0) {
  }

  virtual ~JobSubmissionInterface() throw();
  std::string jobSubmissionInterfaceId;
  JobSubmissionProtocol::type jobSubmissionProtocol;
  int32_t priorityOrder;

  void __set_jobSubmissionInterfaceId(const std::string& val);

  void __set_jobSubmissionProtocol(const JobSubmissionProtocol::type val);

  void __set_priorityOrder(const int32_t val);

  bool operator == (const JobSubmissionInterface & rhs) const
  {
    if (!(jobSubmissionInterfaceId == rhs.jobSubmissionInterfaceId))
      return false;
    if (!(jobSubmissionProtocol == rhs.jobSubmissionProtocol))
      return false;
    if (!(priorityOrder == rhs.priorityOrder))
      return false;
    return true;
  }
  bool operator != (const JobSubmissionInterface &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const JobSubmissionInterface & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(JobSubmissionInterface &a, JobSubmissionInterface &b);

inline std::ostream& operator<<(std::ostream& out, const JobSubmissionInterface& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _ComputeResourceDescription__isset {
  _ComputeResourceDescription__isset() : hostAliases(false), ipAddresses(false), resourceDescription(false), enabled(false), batchQueues(false), fileSystems(false), jobSubmissionInterfaces(false), dataMovementInterfaces(false), maxMemoryPerNode(false), gatewayUsageReporting(false), gatewayUsageModuleLoadCommand(false), gatewayUsageExecutable(false) {}
  bool hostAliases :1;
  bool ipAddresses :1;
  bool resourceDescription :1;
  bool enabled :1;
  bool batchQueues :1;
  bool fileSystems :1;
  bool jobSubmissionInterfaces :1;
  bool dataMovementInterfaces :1;
  bool maxMemoryPerNode :1;
  bool gatewayUsageReporting :1;
  bool gatewayUsageModuleLoadCommand :1;
  bool gatewayUsageExecutable :1;
} _ComputeResourceDescription__isset;

class ComputeResourceDescription {
 public:

  ComputeResourceDescription(const ComputeResourceDescription&);
  ComputeResourceDescription& operator=(const ComputeResourceDescription&);
  ComputeResourceDescription() : computeResourceId("DO_NOT_SET_AT_CLIENTS"), hostName(), resourceDescription(), enabled(0), maxMemoryPerNode(0), gatewayUsageReporting(0), gatewayUsageModuleLoadCommand(), gatewayUsageExecutable() {
  }

  virtual ~ComputeResourceDescription() throw();
  std::string computeResourceId;
  std::string hostName;
  std::vector<std::string>  hostAliases;
  std::vector<std::string>  ipAddresses;
  std::string resourceDescription;
  bool enabled;
  std::vector<BatchQueue>  batchQueues;
  std::map<FileSystems::type, std::string>  fileSystems;
  std::vector<JobSubmissionInterface>  jobSubmissionInterfaces;
  std::vector< ::apache::airavata::model::data::movement::DataMovementInterface>  dataMovementInterfaces;
  int32_t maxMemoryPerNode;
  bool gatewayUsageReporting;
  std::string gatewayUsageModuleLoadCommand;
  std::string gatewayUsageExecutable;

  _ComputeResourceDescription__isset __isset;

  void __set_computeResourceId(const std::string& val);

  void __set_hostName(const std::string& val);

  void __set_hostAliases(const std::vector<std::string> & val);

  void __set_ipAddresses(const std::vector<std::string> & val);

  void __set_resourceDescription(const std::string& val);

  void __set_enabled(const bool val);

  void __set_batchQueues(const std::vector<BatchQueue> & val);

  void __set_fileSystems(const std::map<FileSystems::type, std::string> & val);

  void __set_jobSubmissionInterfaces(const std::vector<JobSubmissionInterface> & val);

  void __set_dataMovementInterfaces(const std::vector< ::apache::airavata::model::data::movement::DataMovementInterface> & val);

  void __set_maxMemoryPerNode(const int32_t val);

  void __set_gatewayUsageReporting(const bool val);

  void __set_gatewayUsageModuleLoadCommand(const std::string& val);

  void __set_gatewayUsageExecutable(const std::string& val);

  bool operator == (const ComputeResourceDescription & rhs) const
  {
    if (!(computeResourceId == rhs.computeResourceId))
      return false;
    if (!(hostName == rhs.hostName))
      return false;
    if (__isset.hostAliases != rhs.__isset.hostAliases)
      return false;
    else if (__isset.hostAliases && !(hostAliases == rhs.hostAliases))
      return false;
    if (__isset.ipAddresses != rhs.__isset.ipAddresses)
      return false;
    else if (__isset.ipAddresses && !(ipAddresses == rhs.ipAddresses))
      return false;
    if (__isset.resourceDescription != rhs.__isset.resourceDescription)
      return false;
    else if (__isset.resourceDescription && !(resourceDescription == rhs.resourceDescription))
      return false;
    if (__isset.enabled != rhs.__isset.enabled)
      return false;
    else if (__isset.enabled && !(enabled == rhs.enabled))
      return false;
    if (__isset.batchQueues != rhs.__isset.batchQueues)
      return false;
    else if (__isset.batchQueues && !(batchQueues == rhs.batchQueues))
      return false;
    if (__isset.fileSystems != rhs.__isset.fileSystems)
      return false;
    else if (__isset.fileSystems && !(fileSystems == rhs.fileSystems))
      return false;
    if (__isset.jobSubmissionInterfaces != rhs.__isset.jobSubmissionInterfaces)
      return false;
    else if (__isset.jobSubmissionInterfaces && !(jobSubmissionInterfaces == rhs.jobSubmissionInterfaces))
      return false;
    if (__isset.dataMovementInterfaces != rhs.__isset.dataMovementInterfaces)
      return false;
    else if (__isset.dataMovementInterfaces && !(dataMovementInterfaces == rhs.dataMovementInterfaces))
      return false;
    if (__isset.maxMemoryPerNode != rhs.__isset.maxMemoryPerNode)
      return false;
    else if (__isset.maxMemoryPerNode && !(maxMemoryPerNode == rhs.maxMemoryPerNode))
      return false;
    if (__isset.gatewayUsageReporting != rhs.__isset.gatewayUsageReporting)
      return false;
    else if (__isset.gatewayUsageReporting && !(gatewayUsageReporting == rhs.gatewayUsageReporting))
      return false;
    if (__isset.gatewayUsageModuleLoadCommand != rhs.__isset.gatewayUsageModuleLoadCommand)
      return false;
    else if (__isset.gatewayUsageModuleLoadCommand && !(gatewayUsageModuleLoadCommand == rhs.gatewayUsageModuleLoadCommand))
      return false;
    if (__isset.gatewayUsageExecutable != rhs.__isset.gatewayUsageExecutable)
      return false;
    else if (__isset.gatewayUsageExecutable && !(gatewayUsageExecutable == rhs.gatewayUsageExecutable))
      return false;
    return true;
  }
  bool operator != (const ComputeResourceDescription &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ComputeResourceDescription & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ComputeResourceDescription &a, ComputeResourceDescription &b);

inline std::ostream& operator<<(std::ostream& out, const ComputeResourceDescription& obj)
{
  obj.printTo(out);
  return out;
}

}}}}} // namespace

#endif
