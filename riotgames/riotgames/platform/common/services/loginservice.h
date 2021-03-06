#pragma once

#include "flex/services.h"
#include "../domain/authenticationcredentials.h"

namespace riotgames {
	namespace platform {
		namespace common {
			namespace services {
				using namespace riotgames::platform::common::domain;

				class LoginService : private flex::messaging::services::Service {
				public:
					LoginService()
						: flex::messaging::services::Service("loginService")
					{
					}

					void performLCDSHeartBeat(double accountId, const std::string& serverSessionToken, int heartbeatId, const std::string& datetime, const rtmp::CommandCallback& callback){
						invoke("performLCDSHeartBeat", callback, accountId, serverSessionToken, heartbeatId, datetime);
					}

					void getLoggedInAccountView(const rtmp::CommandCallback& callback){
						invoke("getLoggedInAccountView", callback);
					}

					void login(const std::string& username, const std::string& password, const std::string& authToken, const std::string& domain, const std::string& ipAddress, const std::string& locale, const std::string& clientVersion, const rtmp::CommandCallback& callback){
						AuthenticationCredentials* auth = new AuthenticationCredentials();
						auth->setUsername(username);
						auth->setPassword(password);
						auth->setAuthToken(authToken);
						auth->setDomain(domain);
						auth->setIpAddress(ipAddress);
						auth->setLocale(locale);
						auth->setClientVersion(clientVersion);
						invoke("login", callback, auth);
					}

					void logout(const std::string& param1, const rtmp::CommandCallback& callback){
						invoke("logout", callback, param1);
					}

					void getStoreUrl(const rtmp::CommandCallback& callback){
						invoke("getStoreUrl", callback);
					}

					void authenticateChannel(const std::string& param1, const std::string& param2, const rtmp::CommandCallback& callback){
						invoke("authenticateChannel", callback, param1, param2);
					}

					/*
					void loginWithSuppliedCredentials(const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4, const std::string& param5, const std::string& param6, const std::string& param7, const rtmp::CommandCallback& callback){
						invoke("loginWithSuppliedCredentials", callback, param1, param2, param3, param4, param5, param6, param7);
					}
					*/
				};

				extern LoginService loginService;
			};
		};
	};
};
