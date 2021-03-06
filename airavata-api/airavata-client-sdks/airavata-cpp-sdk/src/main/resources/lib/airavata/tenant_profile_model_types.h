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
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef tenant_profile_model_TYPES_H
#define tenant_profile_model_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "airavata_commons_types.h"


namespace apache { namespace airavata { namespace model { namespace tenant {

struct TenantApprovalStatus {
  enum type {
    REQUESTED = 0,
    APPROVED = 1,
    ACTIVE = 2,
    DEACTIVATED = 3,
    CANCELLED = 4,
    DENIED = 5,
    CREATED = 6,
    DEPLOYED = 7
  };
};

extern const std::map<int, const char*> _TenantApprovalStatus_VALUES_TO_NAMES;

class TenantPreferences;

class TenantConfig;

class Tenant;

typedef struct _TenantPreferences__isset {
  _TenantPreferences__isset() : tenantAdminFirstName(false), tenantAdminLastName(false), tenantAdminEmail(false) {}
  bool tenantAdminFirstName :1;
  bool tenantAdminLastName :1;
  bool tenantAdminEmail :1;
} _TenantPreferences__isset;

class TenantPreferences : public virtual ::apache::thrift::TBase {
 public:

  TenantPreferences(const TenantPreferences&);
  TenantPreferences& operator=(const TenantPreferences&);
  TenantPreferences() : tenantAdminFirstName(), tenantAdminLastName(), tenantAdminEmail() {
  }

  virtual ~TenantPreferences() throw();
  std::string tenantAdminFirstName;
  std::string tenantAdminLastName;
  std::string tenantAdminEmail;

  _TenantPreferences__isset __isset;

  void __set_tenantAdminFirstName(const std::string& val);

  void __set_tenantAdminLastName(const std::string& val);

  void __set_tenantAdminEmail(const std::string& val);

  bool operator == (const TenantPreferences & rhs) const
  {
    if (__isset.tenantAdminFirstName != rhs.__isset.tenantAdminFirstName)
      return false;
    else if (__isset.tenantAdminFirstName && !(tenantAdminFirstName == rhs.tenantAdminFirstName))
      return false;
    if (__isset.tenantAdminLastName != rhs.__isset.tenantAdminLastName)
      return false;
    else if (__isset.tenantAdminLastName && !(tenantAdminLastName == rhs.tenantAdminLastName))
      return false;
    if (__isset.tenantAdminEmail != rhs.__isset.tenantAdminEmail)
      return false;
    else if (__isset.tenantAdminEmail && !(tenantAdminEmail == rhs.tenantAdminEmail))
      return false;
    return true;
  }
  bool operator != (const TenantPreferences &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TenantPreferences & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TenantPreferences &a, TenantPreferences &b);

inline std::ostream& operator<<(std::ostream& out, const TenantPreferences& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TenantConfig__isset {
  _TenantConfig__isset() : oauthClientId(false), oauthClientSecret(false), identityServerUserName(false), identityServerPasswordToken(false) {}
  bool oauthClientId :1;
  bool oauthClientSecret :1;
  bool identityServerUserName :1;
  bool identityServerPasswordToken :1;
} _TenantConfig__isset;

class TenantConfig : public virtual ::apache::thrift::TBase {
 public:

  TenantConfig(const TenantConfig&);
  TenantConfig& operator=(const TenantConfig&);
  TenantConfig() : oauthClientId(), oauthClientSecret(), identityServerUserName(), identityServerPasswordToken() {
  }

  virtual ~TenantConfig() throw();
  std::string oauthClientId;
  std::string oauthClientSecret;
  std::string identityServerUserName;
  std::string identityServerPasswordToken;

  _TenantConfig__isset __isset;

  void __set_oauthClientId(const std::string& val);

  void __set_oauthClientSecret(const std::string& val);

  void __set_identityServerUserName(const std::string& val);

  void __set_identityServerPasswordToken(const std::string& val);

  bool operator == (const TenantConfig & rhs) const
  {
    if (__isset.oauthClientId != rhs.__isset.oauthClientId)
      return false;
    else if (__isset.oauthClientId && !(oauthClientId == rhs.oauthClientId))
      return false;
    if (__isset.oauthClientSecret != rhs.__isset.oauthClientSecret)
      return false;
    else if (__isset.oauthClientSecret && !(oauthClientSecret == rhs.oauthClientSecret))
      return false;
    if (__isset.identityServerUserName != rhs.__isset.identityServerUserName)
      return false;
    else if (__isset.identityServerUserName && !(identityServerUserName == rhs.identityServerUserName))
      return false;
    if (__isset.identityServerPasswordToken != rhs.__isset.identityServerPasswordToken)
      return false;
    else if (__isset.identityServerPasswordToken && !(identityServerPasswordToken == rhs.identityServerPasswordToken))
      return false;
    return true;
  }
  bool operator != (const TenantConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TenantConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TenantConfig &a, TenantConfig &b);

inline std::ostream& operator<<(std::ostream& out, const TenantConfig& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _Tenant__isset {
  _Tenant__isset() : tenantName(false), domain(false), emailAddress(false), tenantAcronym(false), tenantURL(false), tenantPublicAbstract(false), reviewProposalDescription(false), declinedReason(false), requestCreationTime(false), requesterUsername(false) {}
  bool tenantName :1;
  bool domain :1;
  bool emailAddress :1;
  bool tenantAcronym :1;
  bool tenantURL :1;
  bool tenantPublicAbstract :1;
  bool reviewProposalDescription :1;
  bool declinedReason :1;
  bool requestCreationTime :1;
  bool requesterUsername :1;
} _Tenant__isset;

class Tenant : public virtual ::apache::thrift::TBase {
 public:

  Tenant(const Tenant&);
  Tenant& operator=(const Tenant&);
  Tenant() : tenantId(), tenantApprovalStatus((TenantApprovalStatus::type)0), tenantName(), domain(), emailAddress(), tenantAcronym(), tenantURL(), tenantPublicAbstract(), reviewProposalDescription(), declinedReason(), requestCreationTime(0), requesterUsername() {
  }

  virtual ~Tenant() throw();
  std::string tenantId;
  TenantApprovalStatus::type tenantApprovalStatus;
  std::string tenantName;
  std::string domain;
  std::string emailAddress;
  std::string tenantAcronym;
  std::string tenantURL;
  std::string tenantPublicAbstract;
  std::string reviewProposalDescription;
  std::string declinedReason;
  int64_t requestCreationTime;
  std::string requesterUsername;

  _Tenant__isset __isset;

  void __set_tenantId(const std::string& val);

  void __set_tenantApprovalStatus(const TenantApprovalStatus::type val);

  void __set_tenantName(const std::string& val);

  void __set_domain(const std::string& val);

  void __set_emailAddress(const std::string& val);

  void __set_tenantAcronym(const std::string& val);

  void __set_tenantURL(const std::string& val);

  void __set_tenantPublicAbstract(const std::string& val);

  void __set_reviewProposalDescription(const std::string& val);

  void __set_declinedReason(const std::string& val);

  void __set_requestCreationTime(const int64_t val);

  void __set_requesterUsername(const std::string& val);

  bool operator == (const Tenant & rhs) const
  {
    if (!(tenantId == rhs.tenantId))
      return false;
    if (!(tenantApprovalStatus == rhs.tenantApprovalStatus))
      return false;
    if (__isset.tenantName != rhs.__isset.tenantName)
      return false;
    else if (__isset.tenantName && !(tenantName == rhs.tenantName))
      return false;
    if (__isset.domain != rhs.__isset.domain)
      return false;
    else if (__isset.domain && !(domain == rhs.domain))
      return false;
    if (__isset.emailAddress != rhs.__isset.emailAddress)
      return false;
    else if (__isset.emailAddress && !(emailAddress == rhs.emailAddress))
      return false;
    if (__isset.tenantAcronym != rhs.__isset.tenantAcronym)
      return false;
    else if (__isset.tenantAcronym && !(tenantAcronym == rhs.tenantAcronym))
      return false;
    if (__isset.tenantURL != rhs.__isset.tenantURL)
      return false;
    else if (__isset.tenantURL && !(tenantURL == rhs.tenantURL))
      return false;
    if (__isset.tenantPublicAbstract != rhs.__isset.tenantPublicAbstract)
      return false;
    else if (__isset.tenantPublicAbstract && !(tenantPublicAbstract == rhs.tenantPublicAbstract))
      return false;
    if (__isset.reviewProposalDescription != rhs.__isset.reviewProposalDescription)
      return false;
    else if (__isset.reviewProposalDescription && !(reviewProposalDescription == rhs.reviewProposalDescription))
      return false;
    if (__isset.declinedReason != rhs.__isset.declinedReason)
      return false;
    else if (__isset.declinedReason && !(declinedReason == rhs.declinedReason))
      return false;
    if (__isset.requestCreationTime != rhs.__isset.requestCreationTime)
      return false;
    else if (__isset.requestCreationTime && !(requestCreationTime == rhs.requestCreationTime))
      return false;
    if (__isset.requesterUsername != rhs.__isset.requesterUsername)
      return false;
    else if (__isset.requesterUsername && !(requesterUsername == rhs.requesterUsername))
      return false;
    return true;
  }
  bool operator != (const Tenant &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Tenant & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Tenant &a, Tenant &b);

inline std::ostream& operator<<(std::ostream& out, const Tenant& obj)
{
  obj.printTo(out);
  return out;
}

}}}} // namespace

#endif
