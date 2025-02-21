#pragma once

#include <set>
#include "esphome/core/optional.h"
#include "util.h"

namespace esphome
{
    namespace samsung_ac
    {
        extern bool debug_log_raw_bytes;
        extern bool non_nasa_keepalive;
        extern bool debug_log_undefined_messages;
        extern bool debug_log_messages;

        enum class DecodeResult
        {
            Ok = 0,
            InvalidStartByte = 1,
            InvalidEndByte = 2,
            SizeDidNotMatch = 3,
            UnexpectedSize = 4,
            CrcError = 5
        };

        enum class Mode
        {
            Unknown = -1,
            Auto = 0,
            Cool = 1,
            Dry = 2,
            Fan = 3,
            Heat = 4,
        };

        enum class WaterHeaterMode
        {
            Unknown = -1,
            Eco = 0,
            Standard = 1,
            Power = 2,
            Force = 3,
        };

        enum class FanMode
        {
            Unknown = -1,
            Auto = 0,
            Low = 1,
            Mid = 2,
            High = 3,
            Turbo = 4,
            Off = 5
        };

        typedef std::string AltModeName;
        typedef uint8_t AltMode;

        struct AltModeDesc
        {
            AltModeName name;
            AltMode value;
        };

        enum class SwingMode : uint8_t
        {
            Fix = 0,
            Vertical = 1,
            Horizontal = 2,
            All = 3
        };

        class MessageTarget
        {
        public:
            virtual uint32_t get_miliseconds() = 0;
            virtual void publish_data(std::vector<uint8_t> &data) = 0;
            virtual void register_address(const std::string address) = 0;
            virtual void set_power(const std::string address, bool value) = 0;
            virtual void set_power_zone2(const std::string address, bool value) = 0;
            virtual void set_vacation(const std::string address, bool value) = 0;
            virtual void set_automatic_cleaning(const std::string address, bool value) = 0;
            virtual void set_water_heater_power(const std::string address, bool value) = 0;
            virtual void set_room_temperature(const std::string address, float value) = 0;
            virtual void set_current_temp_zone1(const std::string address, float value) = 0;
            virtual void set_water_temperature_out(const std::string address, float value) = 0;
            virtual void set_discharge_temp(const std::string address, float value) = 0;
            virtual void set_water_pressure(const std::string address, float value) = 0;
            virtual void set_3way_valve(const std::string address, float value) = 0;
            virtual void set_temp_mixing_valve(const std::string address, float value) = 0;
            virtual void set_waterflow(const std::string address, float value) = 0;
            virtual void set_coolant(const std::string address, float value) = 0;
            virtual void set_compressor_frequency(const std::string address, float value) = 0;
            virtual void set_compressor_frequency_order(const std::string address, float value) = 0;
            virtual void set_compressor_frequency_target(const std::string address, float value) = 0;
            virtual void set_energy_produced_lifetime(const std::string address, float value) = 0;
            virtual void set_energy_produced_now(const std::string address, float value) = 0;
            virtual void set_base_heater(const std::string address, float value) = 0;
            virtual void set_backup_heater(const std::string address, float value) = 0;
            virtual void set_booster_heater(const std::string address, float value) = 0;
            virtual void set_service(const std::string address, float value) = 0;
            virtual void set_deice_mode(const std::string address, float value) = 0;
            virtual void set_operation_mode_real(const std::string address, float value) = 0;
            virtual void set_evi_bypass_valve(const std::string address, float value) = 0;
            virtual void set_operation_mode_ext(const std::string address, float value) = 0;
            virtual void set_deice_status(const std::string address, float value) = 0;
            virtual void set_compressor_status(const std::string address, float value) = 0;
            virtual void set_current_temp_zone2(const std::string address, float value) = 0;
            virtual void set_target_temperature(const std::string address, float value) = 0;
            virtual void set_water_outlet_target(const std::string address, float value) = 0;
            virtual void set_outdoor_temperature(const std::string address, float value) = 0;
            virtual void set_indoor_eva_in_temperature(const std::string address, float value) = 0;
            virtual void set_indoor_eva_out_temperature(const std::string address, float value) = 0;
            virtual void set_target_water_temperature(const std::string address, float value) = 0;
            virtual void set_target_temperature_zone2(const std::string address, float value) = 0;
            virtual void set_target_offset(const std::string address, float value) = 0;
            virtual void set_mode(const std::string address, Mode mode) = 0;
            virtual void set_water_heater_mode(const std::string address, WaterHeaterMode waterheatermode) = 0;
            virtual void set_fanmode(const std::string address, FanMode fanmode) = 0;
            virtual void set_altmode(const std::string address, AltMode altmode) = 0;
            virtual void set_swing_vertical(const std::string address, bool vertical) = 0;
            virtual void set_swing_horizontal(const std::string address, bool horizontal) = 0;
            virtual void set_custom_sensor(const std::string address, uint16_t message_number, float value) = 0;
            virtual void set_error_code(const std::string address, int error_code) = 0;
            virtual void set_ventilator(const std::string address, int ventilator) = 0;
            virtual void set_waterpump_pwm(const std::string address, int waterpump_pwm) = 0;
            virtual void set_outdoor_instantaneous_power(const std::string &address, float value) = 0;
            virtual void set_outdoor_cumulative_energy(const std::string &address, float value) = 0;
            virtual void set_outdoor_current(const std::string &address, float value) = 0;
            virtual void set_outdoor_voltage(const std::string &address, float value) = 0;

            //SENSOREN
            virtual void set_fsv1011(const std::string address, float value) = 0;
            virtual void set_fsv1012(const std::string address, float value) = 0;
            virtual void set_fsv1021(const std::string address, float value) = 0;
            virtual void set_fsv1022(const std::string address, float value) = 0;
            virtual void set_fsv1031(const std::string address, float value) = 0;
            virtual void set_fsv1032(const std::string address, float value) = 0;
            virtual void set_fsv1041(const std::string address, float value) = 0;
            virtual void set_fsv1042(const std::string address, float value) = 0;
            virtual void set_fsv1051(const std::string address, float value) = 0;
            virtual void set_fsv1052(const std::string address, float value) = 0;
            virtual void set_fsv5011(const std::string address, float value) = 0;
            virtual void set_fsv5012(const std::string address, float value) = 0;
            virtual void set_fsv5013(const std::string address, float value) = 0;
            virtual void set_fsv5014(const std::string address, float value) = 0;
            virtual void set_fsv5015(const std::string address, float value) = 0;
            virtual void set_fsv5016(const std::string address, float value) = 0;
            virtual void set_fsv5017(const std::string address, float value) = 0;
            virtual void set_fsv5018(const std::string address, float value) = 0;
            virtual void set_fsv5019(const std::string address, float value) = 0;
            virtual void set_fsv2012(const std::string address, float value) = 0;
            virtual void set_fsv2021(const std::string address, float value) = 0;
            virtual void set_fsv2022(const std::string address, float value) = 0;
            virtual void set_fsv2031(const std::string address, float value) = 0;
            virtual void set_fsv2032(const std::string address, float value) = 0;
            virtual void set_fsv2051(const std::string address, float value) = 0;
            virtual void set_fsv2052(const std::string address, float value) = 0;
            virtual void set_fsv2061(const std::string address, float value) = 0;
            virtual void set_fsv2062(const std::string address, float value) = 0;
            virtual void set_fsv2071(const std::string address, float value) = 0;
            virtual void set_fsv2072(const std::string address, float value) = 0;
            virtual void set_fsv2041(const std::string address, float value) = 0;
            virtual void set_fsv2081(const std::string address, float value) = 0;
            virtual void set_fsv2091(const std::string address, float value) = 0;
            virtual void set_fsv2092(const std::string address, float value) = 0;
            virtual void set_fsv2093(const std::string address, float value) = 0;
            virtual void set_fsv3011(const std::string address, float value) = 0;
            virtual void set_fsv3041(const std::string address, float value) = 0;
            virtual void set_fsv3042(const std::string address, float value) = 0;
            virtual void set_fsv3043(const std::string address, float value) = 0;
            virtual void set_fsv3045(const std::string address, float value) = 0;
            virtual void set_fsv3046(const std::string address, float value) = 0;
            virtual void set_fsv3061(const std::string address, float value) = 0;
            virtual void set_fsv4061(const std::string address, float value) = 0;
            virtual void set_fsv5022(const std::string address, float value) = 0;
            virtual void set_fsv3021(const std::string address, float value) = 0;
            virtual void set_fsv3022(const std::string address, float value) = 0;
            virtual void set_fsv3023(const std::string address, float value) = 0;
            virtual void set_fsv3024(const std::string address, float value) = 0;
            virtual void set_fsv3025(const std::string address, float value) = 0;
            virtual void set_fsv3026(const std::string address, float value) = 0;
            virtual void set_fsv3031(const std::string address, float value) = 0;
            virtual void set_fsv3032(const std::string address, float value) = 0;
            virtual void set_fsv3033(const std::string address, float value) = 0;
            virtual void set_fsv3044(const std::string address, float value) = 0;
            virtual void set_fsv3051(const std::string address, float value) = 0;
            virtual void set_fsv3052(const std::string address, float value) = 0;
            virtual void set_fsv3071(const std::string address, float value) = 0;
            virtual void set_fsv3081(const std::string address, float value) = 0;
            virtual void set_fsv3082(const std::string address, float value) = 0;
            virtual void set_fsv3083(const std::string address, float value) = 0;
            virtual void set_fsv4011(const std::string address, float value) = 0;
            virtual void set_fsv4013(const std::string address, float value) = 0;
            virtual void set_fsv4021(const std::string address, float value) = 0;
            virtual void set_fsv4022(const std::string address, float value) = 0;
            virtual void set_fsv4023(const std::string address, float value) = 0;
            virtual void set_fsv4025(const std::string address, float value) = 0;
            virtual void set_fsv4031(const std::string address, float value) = 0;
            virtual void set_fsv4032(const std::string address, float value) = 0;



            
        };

        struct ProtocolRequest
        {
        public:
            optional<bool> power;
            optional<bool> power_zone2;
            optional<bool> vacation;
            optional<bool> automatic_cleaning;
            optional<bool> water_heater_power;
            optional<Mode> mode;
            optional<WaterHeaterMode> waterheatermode;
            optional<float> target_temp;
            optional<float> water_outlet_target;
            optional<float> target_water_temp;
            optional<float> target_temp_zone2;
            optional<float> fsv1011;
            optional<float> fsv1012;
            optional<float> fsv1021;
            optional<float> fsv1022;
            optional<float> fsv1031;
            optional<float> fsv1032;
            optional<float> fsv1041;
            optional<float> fsv1042;
            optional<float> fsv1051;
            optional<float> fsv1052;
            optional<float> fsv5011;
            optional<float> fsv5012;
            optional<float> fsv5013;
            optional<float> fsv5014;
            optional<float> fsv5015;
            optional<float> fsv5016;
            optional<float> fsv5017;
            optional<float> fsv5018;
            optional<float> fsv5019;
            optional<float> fsv2012;
            optional<float> fsv2021;
            optional<float> fsv2022;
            optional<float> fsv2031;
            optional<float> fsv2032;
            optional<float> fsv2051;
            optional<float> fsv2052;
            optional<float> fsv2061;
            optional<float> fsv2062;
            optional<float> fsv2071;
            optional<float> fsv2072;
            optional<float> fsv2041;
            optional<float> fsv2081;
            optional<float> fsv2091;
            optional<float> fsv2092;
            optional<float> fsv2093;
            optional<float> fsv3011;
            optional<float> fsv3041;
            optional<float> fsv3042;
            optional<float> fsv3043;
            optional<float> fsv3045;
            optional<float> fsv3046;
            optional<float> fsv3061;
            optional<float> fsv4061;
            optional<float> fsv5022;
            optional<float> fsv3021;
            optional<float> fsv3022;
            optional<float> fsv3023;
            optional<float> fsv3024;
            optional<float> fsv3025;
            optional<float> fsv3026;
            optional<float> fsv3031;
            optional<float> fsv3032;
            optional<float> fsv3033;
            optional<float> fsv3044;
            optional<float> fsv3051;
            optional<float> fsv3052;
            optional<float> fsv3071;
            optional<float> fsv3081;
            optional<float> fsv3082;
            optional<float> fsv3083;
            optional<float> fsv4011;
            optional<float> fsv4013;
            optional<float> fsv4021;
            optional<float> fsv4022;
            optional<float> fsv4023;
            optional<float> fsv4025;
            optional<float> fsv4031;
            optional<float> fsv4032;



            optional<float> target_offset;
            optional<FanMode> fan_mode;
            optional<SwingMode> swing_mode;
            optional<AltMode> alt_mode;
        };

        class Protocol
        {
        public:
            virtual void publish_request(MessageTarget *target, const std::string &address, ProtocolRequest &request) = 0;
            virtual void protocol_update(MessageTarget *target) = 0;
        };

        enum class ProtocolProcessing
        {
            Auto = 0,
            NASA = 1,
            NonNASA = 2
        };

        extern ProtocolProcessing protocol_processing;

        enum class DataResult
        {
            Fill = 0,
            Clear = 1
        };

        DataResult process_data(std::vector<uint8_t> &data, MessageTarget *target);

        Protocol *get_protocol(const std::string &address);

        bool is_nasa_address(const std::string &address);

        enum class AddressType
        {
            Outdoor = 0,
            Indoor = 1,
            Other = 2
        };

        AddressType get_address_type(const std::string &address);

    } // namespace samsung_ac
} // namespace esphome
