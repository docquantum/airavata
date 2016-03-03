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
#ifndef application_deployment_model_TYPES_H
#define application_deployment_model_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "airavata_commons_types.h"
#include "parallelism_model_types.h"


namespace apache { namespace airavata { namespace model { namespace appcatalog { namespace appdeployment {

class SetEnvPaths;

class CommandObject;

class ApplicationModule;

class ApplicationDeploymentDescription;

typedef struct _SetEnvPaths__isset {
  _SetEnvPaths__isset() : envPathOrder(false) {}
  bool envPathOrder :1;
} _SetEnvPaths__isset;

class SetEnvPaths {
 public:

  SetEnvPaths(const SetEnvPaths&);
  SetEnvPaths& operator=(const SetEnvPaths&);
  SetEnvPaths() : name(), value(), envPathOrder(0) {
  }

  virtual ~SetEnvPaths() throw();
  std::string name;
  std::string value;
  int32_t envPathOrder;

  _SetEnvPaths__isset __isset;

  void __set_name(const std::string& val);

  void __set_value(const std::string& val);

  void __set_envPathOrder(const int32_t val);

  bool operator == (const SetEnvPaths & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(value == rhs.value))
      return false;
    if (__isset.envPathOrder != rhs.__isset.envPathOrder)
      return false;
    else if (__isset.envPathOrder && !(envPathOrder == rhs.envPathOrder))
      return false;
    return true;
  }
  bool operator != (const SetEnvPaths &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SetEnvPaths & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(SetEnvPaths &a, SetEnvPaths &b);

inline std::ostream& operator<<(std::ostream& out, const SetEnvPaths& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _CommandObject__isset {
  _CommandObject__isset() : commandOrder(false) {}
  bool commandOrder :1;
} _CommandObject__isset;

class CommandObject {
 public:

  CommandObject(const CommandObject&);
  CommandObject& operator=(const CommandObject&);
  CommandObject() : command(), commandOrder(0) {
  }

  virtual ~CommandObject() throw();
  std::string command;
  int32_t commandOrder;

  _CommandObject__isset __isset;

  void __set_command(const std::string& val);

  void __set_commandOrder(const int32_t val);

  bool operator == (const CommandObject & rhs) const
  {
    if (!(command == rhs.command))
      return false;
    if (__isset.commandOrder != rhs.__isset.commandOrder)
      return false;
    else if (__isset.commandOrder && !(commandOrder == rhs.commandOrder))
      return false;
    return true;
  }
  bool operator != (const CommandObject &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CommandObject & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(CommandObject &a, CommandObject &b);

inline std::ostream& operator<<(std::ostream& out, const CommandObject& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _ApplicationModule__isset {
  _ApplicationModule__isset() : appModuleVersion(false), appModuleDescription(false) {}
  bool appModuleVersion :1;
  bool appModuleDescription :1;
} _ApplicationModule__isset;

class ApplicationModule {
 public:

  ApplicationModule(const ApplicationModule&);
  ApplicationModule& operator=(const ApplicationModule&);
  ApplicationModule() : appModuleId("DO_NOT_SET_AT_CLIENTS"), appModuleName(), appModuleVersion(), appModuleDescription() {
  }

  virtual ~ApplicationModule() throw();
  std::string appModuleId;
  std::string appModuleName;
  std::string appModuleVersion;
  std::string appModuleDescription;

  _ApplicationModule__isset __isset;

  void __set_appModuleId(const std::string& val);

  void __set_appModuleName(const std::string& val);

  void __set_appModuleVersion(const std::string& val);

  void __set_appModuleDescription(const std::string& val);

  bool operator == (const ApplicationModule & rhs) const
  {
    if (!(appModuleId == rhs.appModuleId))
      return false;
    if (!(appModuleName == rhs.appModuleName))
      return false;
    if (__isset.appModuleVersion != rhs.__isset.appModuleVersion)
      return false;
    else if (__isset.appModuleVersion && !(appModuleVersion == rhs.appModuleVersion))
      return false;
    if (__isset.appModuleDescription != rhs.__isset.appModuleDescription)
      return false;
    else if (__isset.appModuleDescription && !(appModuleDescription == rhs.appModuleDescription))
      return false;
    return true;
  }
  bool operator != (const ApplicationModule &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ApplicationModule & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ApplicationModule &a, ApplicationModule &b);

inline std::ostream& operator<<(std::ostream& out, const ApplicationModule& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _ApplicationDeploymentDescription__isset {
  _ApplicationDeploymentDescription__isset() : appDeploymentDescription(false), moduleLoadCmds(false), libPrependPaths(false), libAppendPaths(false), setEnvironment(false), preJobCommands(false), postJobCommands(false) {}
  bool appDeploymentDescription :1;
  bool moduleLoadCmds :1;
  bool libPrependPaths :1;
  bool libAppendPaths :1;
  bool setEnvironment :1;
  bool preJobCommands :1;
  bool postJobCommands :1;
} _ApplicationDeploymentDescription__isset;

class ApplicationDeploymentDescription {
 public:

  ApplicationDeploymentDescription(const ApplicationDeploymentDescription&);
  ApplicationDeploymentDescription& operator=(const ApplicationDeploymentDescription&);
  ApplicationDeploymentDescription() : appDeploymentId("DO_NOT_SET_AT_CLIENTS"), appModuleId(), computeHostId(), executablePath(), parallelism(( ::apache::airavata::model::appcatalog::parallelism::ApplicationParallelismType::type)0), appDeploymentDescription() {
    parallelism = ( ::apache::airavata::model::appcatalog::parallelism::ApplicationParallelismType::type)0;

  }

  virtual ~ApplicationDeploymentDescription() throw();
  std::string appDeploymentId;
  std::string appModuleId;
  std::string computeHostId;
  std::string executablePath;
   ::apache::airavata::model::appcatalog::parallelism::ApplicationParallelismType::type parallelism;
  std::string appDeploymentDescription;
  std::vector<CommandObject>  moduleLoadCmds;
  std::vector<SetEnvPaths>  libPrependPaths;
  std::vector<SetEnvPaths>  libAppendPaths;
  std::vector<SetEnvPaths>  setEnvironment;
  std::vector<CommandObject>  preJobCommands;
  std::vector<CommandObject>  postJobCommands;

  _ApplicationDeploymentDescription__isset __isset;

  void __set_appDeploymentId(const std::string& val);

  void __set_appModuleId(const std::string& val);

  void __set_computeHostId(const std::string& val);

  void __set_executablePath(const std::string& val);

  void __set_parallelism(const  ::apache::airavata::model::appcatalog::parallelism::ApplicationParallelismType::type val);

  void __set_appDeploymentDescription(const std::string& val);

  void __set_moduleLoadCmds(const std::vector<CommandObject> & val);

  void __set_libPrependPaths(const std::vector<SetEnvPaths> & val);

  void __set_libAppendPaths(const std::vector<SetEnvPaths> & val);

  void __set_setEnvironment(const std::vector<SetEnvPaths> & val);

  void __set_preJobCommands(const std::vector<CommandObject> & val);

  void __set_postJobCommands(const std::vector<CommandObject> & val);

  bool operator == (const ApplicationDeploymentDescription & rhs) const
  {
    if (!(appDeploymentId == rhs.appDeploymentId))
      return false;
    if (!(appModuleId == rhs.appModuleId))
      return false;
    if (!(computeHostId == rhs.computeHostId))
      return false;
    if (!(executablePath == rhs.executablePath))
      return false;
    if (!(parallelism == rhs.parallelism))
      return false;
    if (__isset.appDeploymentDescription != rhs.__isset.appDeploymentDescription)
      return false;
    else if (__isset.appDeploymentDescription && !(appDeploymentDescription == rhs.appDeploymentDescription))
      return false;
    if (__isset.moduleLoadCmds != rhs.__isset.moduleLoadCmds)
      return false;
    else if (__isset.moduleLoadCmds && !(moduleLoadCmds == rhs.moduleLoadCmds))
      return false;
    if (__isset.libPrependPaths != rhs.__isset.libPrependPaths)
      return false;
    else if (__isset.libPrependPaths && !(libPrependPaths == rhs.libPrependPaths))
      return false;
    if (__isset.libAppendPaths != rhs.__isset.libAppendPaths)
      return false;
    else if (__isset.libAppendPaths && !(libAppendPaths == rhs.libAppendPaths))
      return false;
    if (__isset.setEnvironment != rhs.__isset.setEnvironment)
      return false;
    else if (__isset.setEnvironment && !(setEnvironment == rhs.setEnvironment))
      return false;
    if (__isset.preJobCommands != rhs.__isset.preJobCommands)
      return false;
    else if (__isset.preJobCommands && !(preJobCommands == rhs.preJobCommands))
      return false;
    if (__isset.postJobCommands != rhs.__isset.postJobCommands)
      return false;
    else if (__isset.postJobCommands && !(postJobCommands == rhs.postJobCommands))
      return false;
    return true;
  }
  bool operator != (const ApplicationDeploymentDescription &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ApplicationDeploymentDescription & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ApplicationDeploymentDescription &a, ApplicationDeploymentDescription &b);

inline std::ostream& operator<<(std::ostream& out, const ApplicationDeploymentDescription& obj)
{
  obj.printTo(out);
  return out;
}

}}}}} // namespace

#endif
