#pragma once

#include <vector>
#include "protocol.h"

namespace esphome
{
    namespace samsung_ac
    {
        enum class AddressClass : uint8_t
        {
            Outdoor = 0x10,
            HTU = 0x11,
            Indoor = 0x20,
            ERV = 0x30,
            Diffuser = 0x35,
            MCU = 0x38,
            RMC = 0x40,
            WiredRemote = 0x50,
            PIM = 0x58,
            SIM = 0x59,
            Peak = 0x5A,
            PowerDivider = 0x5B,
            OnOffController = 0x60,
            WiFiKit = 0x62,
            CentralController = 0x65,
            DMS = 0x6A,
            JIGTester = 0x80,
            BroadcastSelfLayer = 0xB0,
            BroadcastControlLayer = 0xB1,
            BroadcastSetLayer = 0xB2,
            BroadcastControlAndSetLayer = 0xB3,
            BroadcastModuleLayer = 0xB4,
            BroadcastCSM = 0xB7,
            BroadcastLocalLayer = 0xB8,
            BroadcastCSML = 0xBF,
            Undefined = 0xFF,
        };

        enum class PacketType : uint8_t
        {
            StandBy = 0,
            Normal = 1,
            Gathering = 2,
            Install = 3,
            Download = 4
        };

        enum class DataType : uint8_t
        {
            Undefined = 0,
            Read = 1,
            Write = 2,
            Request = 3,
            Notification = 4,
            Response = 5,
            Ack = 6,
            Nack = 7
        };

        enum MessageSetType : uint8_t
        {
            Enum = 0,
            Variable = 1,
            LongVariable = 2,
            Structure = 3
        };

        enum class MessageNumber : uint16_t
        {
            Undefiend = 0,
            ENUM_in_operation_power = 0x4000,
            ENUM_in_operation_power_zone2 = 0x411E,
            ENUM_in_request_fsv = 0x4255,
            ENUM_in_operation_quiet_mode = 0x406E,
            ENUM_in_vacation = 0x406D,
            ENUM_in_operation_automatic_cleaning = 0x4111,
            ENUM_in_water_heater_power = 0x4065,
            ENUM_in_operation_mode = 0x4001,
            ENUM_in_water_heater_mode = 0x4066,
            ENUM_in_fan_mode = 0x4006, // Did not exists in xml...only in Remocon.dll code
            ENUM_in_fan_mode_real = 0x4007,
            ENUM_in_alt_mode = 0x4060,
            ENUM_in_louver_hl_swing = 0x4011,
            ENUM_in_louver_lr_swing = 0x407e,
            ENUM_in_state_humidity_percent = 0x4038,
            VAR_in_temp_room_f = 0x4203,
            VAR_in_temp_target_f = 0x4201,
            VAR_in_temp_water_outlet_target_f = 0x4247,
            VAR_in_temp_water_tank_f = 0x4237,
            VAR_out_sensor_airout = 0x8204,
            VAR_in_temp_water_heater_target_f = 0x4235,
            VAR_in_temp_eva_in_f = 0x4205,
            VAR_in_temp_eva_out_f = 0x4206,
            VAR_out_error_code = 0x8235,
            LVAR_OUT_CONTROL_WATTMETER_1W_1MIN_SUM = 0x8413,
            LVAR_OUT_CONTROL_WATTMETER_ALL_UNIT_ACCUM = 0x8414,
            VAR_OUT_SENSOR_CT1 = 0x8217,
            LVAR_NM_OUT_SENSOR_VOLTAGE = 0x24fc,
            VAR_in_temp_target_zone2 = 0x42D7,
            VAR_in_target_offset = 0x4248,

            //Zusätzliche SENSOREN
            VAR_out_compressor_protection = 0x80A6,
            VAR_in_3way_valve = 0x4067,
            VAR_in_deice_status = 0x402E,
            VAR_out_compressor_status = 0x8010,
            VAR_out_deice_mode = 0x8061,
            VAR_in_operation_mode_real = 0x4002,
            VAR_out_evi_bypass_valve = 0x8021,
            VAR_out_operation_mode_ext = 0x8001,
            VAR_out_base_heater = 0x80AF,
            VAR_in_backup_heater = 0x406C,
            VAR_in_booster_heater = 0x4087,
            VAR_in_service = 0x8000,
            VAR_in_energy_produced_lifetime = 0x4427,
            VAR_in_energy_produced_now = 0x4426,
            VAR_out_compressor_frequency = 0x8238,
            VAR_in_waterflow = 0x42E9,
            VAR_out_coolant = 0x808E,
            VAR_in_current_temp_zone1 = 0x42D8,
            VAR_in_current_temp_zone2 = 0x42D9,
            VAR_in_water_temperature_out = 0x4238,
            VAR_out_discharge_temp = 0x820A,
            VAR_in_water_pressure = 0x82FE,
            VAR_in_temp_mixing_valve = 0x428C,
            VAR_in_fsv1011 = 0x424A,
            VAR_in_fsv1012 = 0x424B,
            VAR_in_fsv1021 = 0x424C,
            VAR_in_fsv1022 = 0x424D,
            VAR_in_fsv1031 = 0x424E,
            VAR_in_fsv1032 = 0x424F,
            VAR_in_fsv1041 = 0x4250,
            VAR_in_fsv1042 = 0x4251,
            VAR_in_fsv1051 = 0x4252,
            VAR_in_fsv1052 = 0x4253,
            VAR_in_fsv5011 = 0x4273,
            VAR_in_fsv5012 = 0x4274,
            VAR_in_fsv5013 = 0x4275,
            VAR_in_fsv5014 = 0x4276,
            VAR_in_fsv5015 = 0x4277,
            VAR_in_fsv5016 = 0x4278,
            VAR_in_fsv5017 = 0x4279,
            VAR_in_fsv5018 = 0x427A,
            VAR_in_fsv5019 = 0x427B,
            VAR_in_fsv2012 = 0x4255,

            
            VAR_out_ventilator = 0x823D,
            VAR_in_waterpump_pwm = 0x40C4,


        };

        struct Address
        {
            AddressClass klass;
            uint8_t channel;
            uint8_t address;
            uint8_t size = 3;

            static Address parse(const std::string &str);
            static Address get_my_address();

            void decode(std::vector<uint8_t> &data, unsigned int index);
            void encode(std::vector<uint8_t> &data);
            std::string to_string();
        };

        struct Command
        {
            bool packetInformation = true;
            uint8_t protocolVersion = 2;
            uint8_t retryCount = 0;
            PacketType packetType = PacketType::StandBy;
            DataType dataType = DataType::Undefined;
            uint8_t packetNumber = 0;

            uint8_t size = 3;

            void decode(std::vector<uint8_t> &data, unsigned int index);
            void encode(std::vector<uint8_t> &data);
            std::string to_string();
        };

        struct Buffer
        {
            uint8_t size;
            uint8_t data[255];
        };

        struct MessageSet
        {
            MessageNumber messageNumber = MessageNumber::Undefiend;
            MessageSetType type = Enum;
            union
            {
                long value;
                Buffer structure;
            };
            uint16_t size = 2;

            MessageSet(MessageNumber messageNumber)
            {
                this->messageNumber = messageNumber;
                // this->deviceType = (NMessageSet.DeviceType) (((int) messageNumber & 57344) >> 13);
                this->type = (MessageSetType)(((uint32_t)messageNumber & 1536) >> 9);
                // this->_msgIndex = (ushort) ((uint) messageNumber & 511U);
            }

            static MessageSet decode(std::vector<uint8_t> &data, unsigned int index, int capacity);

            void encode(std::vector<uint8_t> &data);
            std::string to_string();
        };

        struct Packet
        {
            Address sa;
            Address da;
            Command command;
            std::vector<MessageSet> messages;

            static Packet create(Address da, DataType dataType, MessageNumber messageNumber, int value);
            static Packet createa_partial(Address da, DataType dataType);

            DecodeResult decode(std::vector<uint8_t> &data);
            std::vector<uint8_t> encode();
            std::string to_string();
        };

        DecodeResult try_decode_nasa_packet(std::vector<uint8_t> data);
        void process_nasa_packet(MessageTarget *target);

        class NasaProtocol : public Protocol
        {
        public:
            NasaProtocol() = default;

            void publish_request(MessageTarget *target, const std::string &address, ProtocolRequest &request) override;
            void protocol_update(MessageTarget *target) override;
        };

    } // namespace samsung_ac
} // namespace esphome
