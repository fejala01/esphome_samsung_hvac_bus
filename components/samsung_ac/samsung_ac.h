#pragma once

#include <set>
#include <map>
#include <optional>
#include <queue>
#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"
#include "samsung_ac_device.h"
#include "protocol.h"
#include "device_state_tracker.h"

namespace esphome
{
  namespace samsung_ac
  {
    class NasaProtocol;
    class Samsung_AC_Device;

    class Samsung_AC : public PollingComponent,
                       public uart::UARTDevice,
                       public MessageTarget
    {
    public:
      Samsung_AC() = default;

      float get_setup_priority() const override;
      void setup() override;
      void update() override;
      void loop() override;
      void dump_config() override;

      template <typename SensorType, typename ValueType>
      void update_device_sensor(const std::string &address, SensorType Samsung_AC_Device::*sensor_ptr, ValueType value)
      {
        Samsung_AC_Device *dev = find_device(address);
        if (dev != nullptr && dev->*sensor_ptr != nullptr)
        {
          dev->update_sensor_state(dev->*sensor_ptr, value);
        }
      }

      template <typename Func>
      void execute_if_device_exists(const std::string &address, Func func)
      {
        Samsung_AC_Device *dev = find_device(address);
        if (dev != nullptr)
        {
          func(dev);
        }
      }

      void set_debug_mqtt(std::string host, int port, std::string username, std::string password)
      {
        debug_mqtt_host = host;
        debug_mqtt_port = port;
        debug_mqtt_username = username;
        debug_mqtt_password = password;
      }

      void set_debug_log_messages(bool value)
      {
        debug_log_messages = value;
      }

      void set_debug_log_messages_raw(bool value)
      {
        debug_log_raw_bytes = value;
      }

      void set_non_nasa_keepalive(bool value)
      {
        non_nasa_keepalive = value;
      }
      void set_debug_log_undefined_messages(bool value)
      {
        debug_log_undefined_messages = value;
      }

      void register_device(Samsung_AC_Device *device);

      void register_address(const std::string address) override
      {
        addresses_.insert(address);
      }

      uint32_t get_miliseconds()
      {
        return millis();
      }

      void publish_data(std::vector<uint8_t> &data);

      void set_room_temperature(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_room_temperature(value); });
      }

      void set_outdoor_temperature(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->outdoor_temperature, value); });
      }
      void set_current_temp_zone1(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->current_temp_zone1, value); });
      }
      void set_water_temperature_out(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->water_temperature_out, value); });
      }
      void set_discharge_temp(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->discharge_temp, value); });
      }
      void set_water_pressure(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->water_pressure, value); });
      }
      void set_3way_valve(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->three_way_valve, value); });
      }
      void set_temp_mixing_valve(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->temp_mixing_valve, value); });
      }
      void set_waterflow(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->waterflow, value); });
      }
      void set_coolant(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->coolant, value); });
      }
      void set_compressor_frequency(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->compressor_frequency, value); });
      }
      void set_compressor_frequency_order(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->compressor_frequency_order, value); });
      }
      void set_compressor_frequency_target(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->compressor_frequency_target, value); });
      }
      void set_energy_produced_lifetime(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->energy_produced_lifetime, value); });
      }
      void set_energy_produced_now(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->energy_produced_now, value); });
      }
      void set_base_heater(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->base_heater, value); });
      }
      void set_backup_heater(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->backup_heater, value); });
      }
      void set_booster_heater(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->booster_heater, value); });
      }
      void set_service(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->service, value); });
      }
      void set_deice_mode(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->deice_mode, value); });
      }
      void set_operation_mode_real(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->operation_mode_real, value); });
      }
      void set_evi_bypass_valve(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->evi_bypass_valve, value); });
      }
      void set_operation_mode_ext(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->operation_mode_ext, value); });
      }
      void set_deice_status(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->deice_status, value); });
      }
      void set_compressor_status(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->compressor_status, value); });
      }
      void set_current_temp_zone2(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->current_temp_zone2, value); });
      }

      //Sensoren
      
      void set_indoor_eva_in_temperature(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->indoor_eva_in_temperature, value); });
      }

      void set_indoor_eva_out_temperature(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_sensor_state(dev->indoor_eva_out_temperature, value); });
      }

      void set_target_temperature(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_target_temperature(value); });
      }

      void set_water_outlet_target(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_water_outlet_target(value); });
      }

      void set_target_water_temperature(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_target_water_temperature(value); });
      }
      void set_target_temperature_zone2(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_target_temperature_zone2(value); });
      }
      
      void set_fsv1011(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv1011(value); });
      }
      void set_fsv2012(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv2012(value); });
      }
      void set_fsv1012(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv1012(value); });
      }
      void set_fsv1021(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv1021(value); });
      }
      void set_fsv1022(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv1022(value); });
      }
      void set_fsv1031(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv1031(value); });
      }
      void set_fsv1032(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv1032(value); });
      }
      void set_fsv1041(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv1041(value); });
      }
      void set_fsv1042(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv1042(value); });
      }
      void set_fsv1051(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv1051(value); });
      }
      void set_fsv1052(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv1052(value); });
      }
      void set_fsv5011(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv5011(value); });
      }
      void set_fsv5012(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv5012(value); });
      }
      void set_fsv5013(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv5013(value); });
      }
      void set_fsv5014(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv5014(value); });
      }
      void set_fsv5015(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv5015(value); });
      }
      void set_fsv5016(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv5016(value); });
      }
      void set_fsv5017(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv5017(value); });
      }
      void set_fsv5018(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv5018(value); });
      }
      void set_fsv5019(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv5019(value); });
      }
      void set_fsv2071(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv2071(value); });
      }
      void set_fsv2072(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv2072(value); });
      }
      void set_fsv2021(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv2021(value); });
      }
      void set_fsv2022(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv2022(value); });
      }
      void set_fsv2031(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv2031(value); });
      }
      void set_fsv2032(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv2032(value); });
      }
      void set_fsv2051(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv2051(value); });
      }
      void set_fsv2052(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv2052(value); });
      }
      void set_fsv2061(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv2061(value); });
      }
      void set_fsv2062(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                    { dev->update_fsv2062(value); });
      }
      void set_fsv2041(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv2041(value); });
      }

      void set_fsv2081(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv2081(value); });
      }

      void set_fsv2091(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv2091(value); });
      }

      void set_fsv2092(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv2092(value); });
      }

      void set_fsv2093(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv2093(value); });
      }

      void set_fsv3011(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3011(value); });
      }

      void set_fsv3041(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3041(value); });
      }

      void set_fsv3042(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3042(value); });
      }
      void set_fsv3043(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3043(value); });
      }

      void set_fsv3045(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3045(value); });
      }

      void set_fsv3046(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3046(value); });
      }

      void set_fsv3061(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3061(value); });
      }

      void set_fsv4061(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv4061(value); });
      }

      void set_fsv5022(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv5022(value); });
      }

      void set_fsv3021(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3021(value); });
      }

      void set_fsv3022(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3022(value); });
      }

      void set_fsv3023(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3023(value); });
      }

      void set_fsv3024(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3024(value); });
      }

      void set_fsv3025(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3025(value); });
      }

      void set_fsv3026(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3026(value); });
      }

      void set_fsv3031(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3031(value); });
      }

      void set_fsv3032(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3032(value); });
      }

      void set_fsv3033(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3033(value); });
      }

      void set_fsv3044(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3044(value); });
      }

      void set_fsv3051(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3051(value); });
      }

      void set_fsv3052(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3052(value); });
      }

      void set_fsv3071(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3071(value); });
      }

      void set_fsv3081(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3081(value); });
      }

      void set_fsv3082(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3082(value); });
      }

      void set_fsv3083(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv3083(value); });
      }

      void set_fsv4011(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv4011(value); });
      }

      void set_fsv4013(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv4013(value); });
      }

      void set_fsv4021(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv4021(value); });
      }

      void set_fsv4022(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv4022(value); });
      }

      void set_fsv4023(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv4023(value); });
      }

      void set_fsv4025(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv4025(value); });
      }

      void set_fsv4031(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv4031(value); });
      }

      void set_fsv4032(const std::string address, float value) override
      {
          execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
          { dev->update_fsv4032(value); });
      }





      void set_target_offset(const std::string address, float value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_target_offset(value); });
      }

      void set_power(const std::string address, bool value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_power(value); });
      }
      void set_power_zone2(const std::string address, bool value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_power_zone2(value); });
      }
      void set_vacation(const std::string address, bool value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_vacation(value); });
      }
      void set_automatic_cleaning(const std::string address, bool value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_automatic_cleaning(value); });
      }

      void set_water_heater_power(const std::string address, bool value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_water_heater_power(value); });
      }

      void set_mode(const std::string address, Mode mode) override
      {
        execute_if_device_exists(address, [mode](Samsung_AC_Device *dev)
                                 { dev->update_mode(mode); });
      }

      void set_water_heater_mode(const std::string address, WaterHeaterMode waterheatermode) override
      {
        execute_if_device_exists(address, [waterheatermode](Samsung_AC_Device *dev)
                                 { dev->update_water_heater_mode(waterheatermode); });
      }

      void set_fanmode(const std::string address, FanMode fanmode) override
      {
        execute_if_device_exists(address, [fanmode](Samsung_AC_Device *dev)
                                 { dev->update_fanmode(fanmode); });
      }

      void set_altmode(const std::string address, AltMode altmode) override
      {
        execute_if_device_exists(address, [altmode](Samsung_AC_Device *dev)
                                 { dev->update_altmode(altmode); });
      }

      void set_swing_vertical(const std::string address, bool vertical) override
      {
        execute_if_device_exists(address, [vertical](Samsung_AC_Device *dev)
                                 { dev->update_swing_vertical(vertical); });
      }

      void set_swing_horizontal(const std::string address, bool horizontal) override
      {
        execute_if_device_exists(address, [horizontal](Samsung_AC_Device *dev)
                                 { dev->update_swing_horizontal(horizontal); });
      }

      void set_custom_sensor(const std::string address, uint16_t message_number, float value) override
      {
        execute_if_device_exists(address, [message_number, value](Samsung_AC_Device *dev)
                                 { dev->update_custom_sensor(message_number, value); });
      }

      void set_error_code(const std::string address, int value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_error_code(value); });
      }
      void set_ventilator(const std::string address, int value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_ventilator(value); });
      }
      void set_waterpump_pwm(const std::string address, int value) override
      {
        execute_if_device_exists(address, [value](Samsung_AC_Device *dev)
                                 { dev->update_waterpump_pwm(value); });
      }

      void set_outdoor_instantaneous_power(const std::string &address, float value)
      {
        update_device_sensor(address, &Samsung_AC_Device::outdoor_instantaneous_power, value);
      }

      void set_outdoor_cumulative_energy(const std::string &address, float value)
      {
        update_device_sensor(address, &Samsung_AC_Device::outdoor_cumulative_energy, value);
      }

      void set_outdoor_current(const std::string &address, float value)
      {
        update_device_sensor(address, &Samsung_AC_Device::outdoor_current, value);
      }

      void set_outdoor_voltage(const std::string &address, float value)
      {
        update_device_sensor(address, &Samsung_AC_Device::outdoor_voltage, value);
      }

    protected:
      Samsung_AC_Device *find_device(const std::string &address)
      {
        auto it = devices_.find(address);
        if (it != devices_.end())
        {
          return it->second;
        }
        return nullptr;
      }

      std::map<std::string, Samsung_AC_Device *> devices_;
      DeviceStateTracker<Mode> state_tracker_{1000};
      std::set<std::string> addresses_;

      std::vector<uint8_t> data_;
      uint32_t last_transmission_ = 0;
      uint32_t last_protocol_update_ = 0;

      bool data_processing_init = true;

      // settings from yaml
      std::string debug_mqtt_host = "";
      uint16_t debug_mqtt_port = 1883;
      std::string debug_mqtt_username = "";
      std::string debug_mqtt_password = "";
    };

  } // namespace samsung_ac
} // namespace esphome
