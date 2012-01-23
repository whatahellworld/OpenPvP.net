#pragma once

#include "amf/variant.h"
#include "flex/iexternalizable.h"
#include <iostream>

namespace riotgames {
	namespace platform {
		namespace gameclient {
			namespace domain {
				namespace broadcast {
					class BroadcastNotification : public amf::Object {
					public:
					};

					class BroadcastNotificationExt : public flex::utils::IExternalizable {
					public:
						BroadcastNotificationExt(){
							amf::Encoder.addExternalizable(this);
						}

						std::string name() const {
							return "com.riotgames.platform.broadcast.BroadcastNotification";
						}

						void readExternal(amf::Object* object, ByteStream& stream){
							uint16 length;
							stream >> length;

							char* json = new char[length];
							stream.read(json, length);
							std::cout << "BroadcastNotificationExt json:" << std::endl << json << std::endl;
							delete [] json;
						}

						void writeExternal(amf::Object* object, ByteStream& stream){
						}
					};
				};
			};
		};
	};
};