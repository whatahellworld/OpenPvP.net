#pragma once

#include "amf/variant.h"

namespace flex {
	namespace messaging {
		namespace messages {
			class AbstractMessage : public amf::Object {
			public:
				AbstractMessage(){
					setName("flex.messaging.messages.AbstractMessage");

					set("body", new amf::Array());
					set("clientId", new amf::Null());
					set("destination", new amf::String());
					set("headers", new amf::Null());
					set("messageId", new amf::String());
					set("timeToLive", new amf::Integer());
					set("timestamp", new amf::Integer());
				}

				amf::Array* body(){
					return get("body")->toArray();
				}

				amf::Object* clientId(){
					return get("clientId")->toObject();
				}

				std::string destination(){
					return get("destination")->toString();
				}

				amf::Object* headers(){
					return get("headers")->toObject();
				}

				std::string messageId(){
					return get("messageId")->toString();
				}

				int timeToLive(){
					return get("timeToLive")->toInt();
				}

				int timestamp(){
					return get("timestamp")->toInt();
				}

				void setBody(amf::Array* value){
					set("body", value);
				}

				void setClientId(amf::Object* value){
					set("clientId", value);
				}

				void setDestination(const std::string& value){
					((amf::String*)get("destination"))->setValue(value);
				}

				void setHeaders(amf::Object* value){
					set("headers", value);
				}

				void setMessageId(const std::string& value){
					((amf::String*)get("messageId"))->setValue(value);
				}
				
				void setTimeToLive(int value){
					((amf::Integer*)get("timeToLive"))->setValue(value);
				}

				void setTimestamp(int value){
					((amf::Integer*)get("timestamp"))->setValue(value);
				}
			};

			class RemotingMessage : public AbstractMessage {
			public:
				RemotingMessage(){
					setName("flex.messaging.messages.RemotingMessage");

					set("operation", new amf::String());
					set("source", new amf::String());
				}

				std::string operation(){
					return get("operation")->toString();
				}

				std::string source(){
					return get("source")->toString();
				}

				void setOperation(const std::string& value){
					((amf::String*)get("operation"))->setValue(value);
				}

				void setSource(const std::string& value){
					((amf::String*)get("source"))->setValue(value);
				}
			};

			class CommandMessage : public AbstractMessage {
			public:
				typedef enum {
					SUBSCRIBE,
					UNSUBSCRIBE,
					POLL,
					CLIENT_SYNC = 4,
					CLIENT_PING,
					CLUSTER_REQUEST = 7,
					LOGIN,
					LOGOUT,
					SESSION_INVALIDATE,
					CONNECT = 20,
					DISCONNECT,
					UNKNOWN = 10000,
				} Operation;

				CommandMessage(){
					setName("flex.messaging.messages.CommandMessage");

					set("operation", new amf::Integer());
					set("correlationId", new amf::Integer());
				}

				int operation(){
					return get("operation")->toInt();
				}

				std::string correlationId(){
					return get("correlationId")->toString();
				}

				void setOperation(int value){
					((amf::Integer*)get("operation"))->setValue(value);
				}

				void setSource(const std::string& value){
					((amf::String*)get("correlationId"))->setValue(value);
				}
			};
		};
	};
};