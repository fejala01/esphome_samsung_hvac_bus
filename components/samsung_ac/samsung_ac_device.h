#pragma once

#include <set>
#include <optional>
#include <algorithm>
#include "esphome/core/helpers.h"
#include "esphome/components/switch/switch.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/select/select.h"
#include "esphome/components/number/number.h"
#include "esphome/components/climate/climate.h"
#include "protocol.h"
#include "samsung_ac.h"
#include "conversions.h"

namespace esphome
{
  namespace samsung_ac
  {
    class Samsung_AC;
    class Samsung_AC_Device;

    class Samsung_AC_Climate : public climate::Climate
    {
    public:
      climate::ClimateTraits traits();
      void control(const climate::ClimateCall &call);
      Samsung_AC_Device *device;

    protected:
      void set_alt_mode_by_name(ProtocolRequest &request, const AltModeName &name);
    };

    class Samsung_AC_Number : public number::Number
    {
    public:
      void control(float value) override
      {
        write_state_(value);
      }
      std::function<void(float)> write_state_;
    };

    class Samsung_AC_Mode_Select : public select::Select
    {
    public:
      void publish_state_(Mode mode)
      {
        this->publish_state(mode_to_str(mode));
      }

      void control(const std::string &value) override
      {
        write_state_(str_to_mode(value));
      }

      std::function<void(Mode)> write_state_;
    };

    class Samsung_AC_Water_Heater_Mode_Select : public select::Select
    {
    public:
      void publish_state_(WaterHeaterMode waterheatermode)
      {
        this->publish_state(water_heater_mode_to_str(waterheatermode));
      }

      void control(const std::string &value) override
      {
        write_state_(str_to_water_heater_mode(value));
      }

      std::function<void(WaterHeaterMode)> write_state_;
    };

    class Samsung_AC_Switch : public switch_::Switch
    {
    public:
      std::function<void(bool)> write_state_;

    protected:
      void write_state(bool state) override
      {
        this->publish_state(state);
        write_state_(state);
      }
    };

    struct Samsung_AC_Sensor
    {
      uint16_t message_number;
      sensor::Sensor *sensor;
    };

    class Samsung_AC_Device
    {
    public:
      Samsung_AC_Device(const std::string &address, MessageTarget *target)
      {
        this->address = address;
        this->target = target;
        this->protocol = get_protocol(address);
      }

      std::string address;
      sensor::Sensor *room_temperature{nullptr};
      sensor::Sensor *current_temp_zone1{nullptr};
      sensor::Sensor *current_temp_zone2{nullptr};
      sensor::Sensor *water_temperature_out{nullptr};
      sensor::Sensor *discharge_temp{nullptr};
      sensor::Sensor *water_pressure{nullptr};
      sensor::Sensor *three_way_valve{nullptr};
      sensor::Sensor *temp_mixing_valve{nullptr};
      sensor::Sensor *waterflow{nullptr};
      sensor::Sensor *coolant{nullptr};
      sensor::Sensor *compressor_frequency{nullptr};
      sensor::Sensor *compressor_frequency_order{nullptr};
      sensor::Sensor *compressor_frequency_target{nullptr};
      sensor::Sensor *energy_produced_lifetime{nullptr};
      sensor::Sensor *energy_produced_now{nullptr};
      sensor::Sensor *base_heater{nullptr};
      sensor::Sensor *backup_heater{nullptr};
      sensor::Sensor *booster_heater{nullptr};
      sensor::Sensor *service{nullptr};
      sensor::Sensor *deice_mode{nullptr};
      sensor::Sensor *operation_mode_real{nullptr};
      sensor::Sensor *evi_bypass_valve{nullptr};
      sensor::Sensor *operation_mode_ext{nullptr};
      sensor::Sensor *deice_status{nullptr};
      sensor::Sensor *compressor_status{nullptr};
      sensor::Sensor *outdoor_temperature{nullptr};
      sensor::Sensor *indoor_eva_in_temperature{nullptr};
      sensor::Sensor *indoor_eva_out_temperature{nullptr};
      sensor::Sensor *error_code{nullptr};
      sensor::Sensor *ventilator{nullptr};
      sensor::Sensor *waterpump_pwm{nullptr};
      sensor::Sensor *outdoor_instantaneous_power{nullptr};
      sensor::Sensor *outdoor_cumulative_energy{nullptr};
      sensor::Sensor *outdoor_current{nullptr};
      sensor::Sensor *outdoor_voltage{nullptr};



      Samsung_AC_Number *target_temperature{nullptr};
      Samsung_AC_Number *water_outlet_target{nullptr};
      Samsung_AC_Number *target_water_temperature{nullptr};
      Samsung_AC_Number *target_temperature_zone2{nullptr};
      Samsung_AC_Number *target_offset{nullptr};
      Samsung_AC_Switch *power{nullptr};
      Samsung_AC_Switch *power_zone2{nullptr};
      Samsung_AC_Switch *vacation{nullptr};
      Samsung_AC_Switch *automatic_cleaning{nullptr};
      Samsung_AC_Switch *water_heater_power{nullptr};
      Samsung_AC_Mode_Select *mode{nullptr};
      Samsung_AC_Water_Heater_Mode_Select *waterheatermode{nullptr};
      Samsung_AC_Climate *climate{nullptr};
      std::map<uint16_t, sensor::Sensor *> custom_sensor_map;

      Samsung_AC_Number *fsv1011{nullptr};
      Samsung_AC_Number *fsv1012{nullptr};
      Samsung_AC_Number *fsv1021{nullptr};
      Samsung_AC_Number *fsv1022{nullptr};
      Samsung_AC_Number *fsv1031{nullptr};
      Samsung_AC_Number *fsv1032{nullptr};
      Samsung_AC_Number *fsv1041{nullptr};
      Samsung_AC_Number *fsv1042{nullptr};
      Samsung_AC_Number *fsv1051{nullptr};
      Samsung_AC_Number *fsv1052{nullptr};
      Samsung_AC_Number *fsv5011{nullptr};
      Samsung_AC_Number *fsv5012{nullptr};
      Samsung_AC_Number *fsv5013{nullptr};
      Samsung_AC_Number *fsv5014{nullptr};
      Samsung_AC_Number *fsv5015{nullptr};
      Samsung_AC_Number *fsv5016{nullptr};
      Samsung_AC_Number *fsv5017{nullptr};
      Samsung_AC_Number *fsv5018{nullptr};
      Samsung_AC_Number *fsv5019{nullptr};
      Samsung_AC_Number *fsv2012{nullptr};
      Samsung_AC_Number *fsv2021{nullptr};
      Samsung_AC_Number *fsv2022{nullptr};
      Samsung_AC_Number *fsv2031{nullptr};
      Samsung_AC_Number *fsv2032{nullptr};
      Samsung_AC_Number *fsv2051{nullptr};
      Samsung_AC_Number *fsv2052{nullptr};
      Samsung_AC_Number *fsv2061{nullptr};
      Samsung_AC_Number *fsv2062{nullptr};
      Samsung_AC_Number *fsv2071{nullptr};
      Samsung_AC_Number *fsv2072{nullptr};
      Samsung_AC_Number *fsv2041{nullptr};
      Samsung_AC_Number *fsv2081{nullptr};
      Samsung_AC_Number *fsv2091{nullptr};
      Samsung_AC_Number *fsv2092{nullptr};
      Samsung_AC_Number *fsv2093{nullptr};
      Samsung_AC_Number *fsv3011{nullptr};
      Samsung_AC_Number *fsv3041{nullptr};
      Samsung_AC_Number *fsv3042{nullptr};
      Samsung_AC_Number *fsv3043{nullptr};
      Samsung_AC_Number *fsv3045{nullptr};
      Samsung_AC_Number *fsv3046{nullptr};
      Samsung_AC_Number *fsv3061{nullptr};
      Samsung_AC_Number *fsv4061{nullptr};
      Samsung_AC_Number *fsv5022{nullptr};
      Samsung_AC_Number *fsv3021{nullptr};
      Samsung_AC_Number *fsv3022{nullptr};
      Samsung_AC_Number *fsv3023{nullptr};
      Samsung_AC_Number *fsv3024{nullptr};
      Samsung_AC_Number *fsv3025{nullptr};
      Samsung_AC_Number *fsv3026{nullptr};
      Samsung_AC_Number *fsv3031{nullptr};
      Samsung_AC_Number *fsv3032{nullptr};
      Samsung_AC_Number *fsv3033{nullptr};
      Samsung_AC_Number *fsv3044{nullptr};
      Samsung_AC_Number *fsv3051{nullptr};
      Samsung_AC_Number *fsv3052{nullptr};
      Samsung_AC_Number *fsv3071{nullptr};
      Samsung_AC_Number *fsv3081{nullptr};
      Samsung_AC_Number *fsv3082{nullptr};
      Samsung_AC_Number *fsv3083{nullptr};
      Samsung_AC_Number *fsv4011{nullptr};
      Samsung_AC_Number *fsv4013{nullptr};
      Samsung_AC_Number *fsv4021{nullptr};
      Samsung_AC_Number *fsv4022{nullptr};
      Samsung_AC_Number *fsv4023{nullptr};
      Samsung_AC_Number *fsv4025{nullptr};
      Samsung_AC_Number *fsv4031{nullptr};
      Samsung_AC_Number *fsv4032{nullptr};





      float room_temperature_offset{0};

      template <typename SwingType>
      void update_swing(SwingType &swing_variable, uint8_t mask, bool value)
      {
        swing_variable = combine(swing_variable, mask, value);
        climate->publish_state();
      }

      void update_sensor_state(sensor::Sensor *target_sensor, float value)
      {
        if (target_sensor != nullptr)
        {
          target_sensor->publish_state(value);
        }
      }

      void set_error_code_sensor(sensor::Sensor *sensor)
      {
        error_code = sensor;
      }
      void set_ventilator_sensor(sensor::Sensor *sensor)
      {
        ventilator = sensor;
      }
      void set_waterpump_pwm_sensor(sensor::Sensor *sensor)
      {
        waterpump_pwm = sensor;
      }

      void update_error_code(int value)
      {
        if (error_code != nullptr)
          error_code->publish_state(value);
      }
      void update_ventilator(int value)
      {
        if (ventilator != nullptr)
          ventilator->publish_state(value);
      }
      void update_waterpump_pwm(int value)
      {
        if (waterpump_pwm != nullptr)
          waterpump_pwm->publish_state(value);
      }

      void set_outdoor_instantaneous_power_sensor(sensor::Sensor *sensor)
      {
        outdoor_instantaneous_power = sensor;
      }

      void set_outdoor_cumulative_energy_sensor(sensor::Sensor *sensor)
      {
        outdoor_cumulative_energy = sensor;
      }

      void set_outdoor_current_sensor(sensor::Sensor *sensor)
      {
        outdoor_current = sensor;
      }

      void set_outdoor_voltage_sensor(sensor::Sensor *sensor)
      {
        outdoor_voltage = sensor;
      }

      void set_outdoor_temperature_sensor(sensor::Sensor *sensor)
      {
        outdoor_temperature = sensor;
      }
      void set_current_temp_zone1_sensor(sensor::Sensor *sensor)
      {
        current_temp_zone1 = sensor;
      }
      void set_current_temp_zone2_sensor(sensor::Sensor *sensor)
      {
        current_temp_zone2 = sensor;
      }
      void set_water_temperature_out_sensor(sensor::Sensor *sensor)
      {
        water_temperature_out = sensor;
      }
      void set_discharge_temp_sensor(sensor::Sensor *sensor)
      {
        discharge_temp = sensor;
      }
      void set_water_pressure_sensor(sensor::Sensor *sensor)
      {
        water_pressure = sensor;
      }
      void set_3way_valve_sensor(sensor::Sensor *sensor)
      {
        three_way_valve = sensor;
      }
      void set_temp_mixing_valve_sensor(sensor::Sensor *sensor)
      {
        temp_mixing_valve = sensor;
      }
      void set_waterflow_sensor(sensor::Sensor *sensor)
      {
        waterflow = sensor;
      }
      void set_coolant_sensor(sensor::Sensor *sensor)
      {
        coolant = sensor;
      }
      void set_compressor_frequency_sensor(sensor::Sensor *sensor)
      {
        compressor_frequency = sensor;
      }
      void set_compressor_frequency_order_sensor(sensor::Sensor *sensor)
      {
        compressor_frequency_order = sensor;
      }
      void set_compressor_frequency_target_sensor(sensor::Sensor *sensor)
      {
        compressor_frequency_target = sensor;
      }
      void set_energy_produced_lifetime_sensor(sensor::Sensor *sensor)
      {
        energy_produced_lifetime = sensor;
      }
      void set_energy_produced_now_sensor(sensor::Sensor *sensor)
      {
        energy_produced_now = sensor;
      }
      void set_base_heater_sensor(sensor::Sensor *sensor)
      {
        base_heater = sensor;
      }
      void set_backup_heater_sensor(sensor::Sensor *sensor)
      {
        backup_heater = sensor;
      }
      void set_booster_heater_sensor(sensor::Sensor *sensor)
      {
        booster_heater = sensor;
      }
      void set_service_sensor(sensor::Sensor *sensor)
      {
        service = sensor;
      }
      void set_deice_status_sensor(sensor::Sensor *sensor)
      {
        deice_status = sensor;
      }
      void set_compressor_status_sensor(sensor::Sensor *sensor)
      {
        compressor_status = sensor;
      }
      void set_deice_mode_sensor(sensor::Sensor *sensor)
      {
        deice_mode = sensor;
      }
      void set_operation_mode_real_sensor(sensor::Sensor *sensor)
      {
        operation_mode_real = sensor;
      }
      void set_evi_bypass_valve_sensor(sensor::Sensor *sensor)
      {
        evi_bypass_valve = sensor;
      }
      void set_operation_mode_ext_sensor(sensor::Sensor *sensor)
      {
        operation_mode_ext = sensor;
      }

      //Sensoren
      void set_indoor_eva_in_temperature_sensor(sensor::Sensor *sensor)
      {
        indoor_eva_in_temperature = sensor;
      }

      void set_indoor_eva_out_temperature_sensor(sensor::Sensor *sensor)
      {
        indoor_eva_out_temperature = sensor;
      }

      void update_custom_sensor(uint16_t message_number, float value)
      {
        auto it = custom_sensor_map.find(message_number);
        if (it != custom_sensor_map.end())
        {
          it->second->publish_state(value);
        }
      }

      void set_room_temperature_sensor(sensor::Sensor *sensor)
      {
        room_temperature = sensor;
      }

      void update_room_temperature(float value)
      {
        if (room_temperature != nullptr)
          room_temperature->publish_state(value + room_temperature_offset);
        if (climate != nullptr)
        {
          climate->current_temperature = value + room_temperature_offset;
          climate->publish_state();
        }
      }

      void add_custom_sensor(int message_number, sensor::Sensor *sensor)
      {
        custom_sensor_map[(uint16_t)message_number] = sensor;
      }

      void set_power_switch(Samsung_AC_Switch *switch_)
      {
        power = switch_;
        power->write_state_ = [this](bool value)
        {
          ProtocolRequest request;
          request.power = value;
          publish_request(request);
        };
      }
      void set_power_zone2_switch(Samsung_AC_Switch *switch_)
      {
        power_zone2 = switch_;
        power_zone2->write_state_ = [this](bool value)
        {
          ProtocolRequest request;
          request.power_zone2 = value;
          publish_request(request);
        };
      }
      void set_vacation_switch(Samsung_AC_Switch *switch_)
      {
        vacation = switch_;
        vacation->write_state_ = [this](bool value)
        {
          ProtocolRequest request;
          request.vacation = value;
          publish_request(request);
        };
      }

      void set_automatic_cleaning_switch(Samsung_AC_Switch *switch_)
      {
        automatic_cleaning = switch_;
        automatic_cleaning->write_state_ = [this](bool value)
        {
          ProtocolRequest request;
          request.automatic_cleaning = value;
          publish_request(request);
        };
      }

      void set_water_heater_power_switch(Samsung_AC_Switch *switch_)
      {
        water_heater_power = switch_;
        water_heater_power->write_state_ = [this](bool value)
        {
          ProtocolRequest request;
          request.water_heater_power = value;
          publish_request(request);
        };
      }

      void set_mode_select(Samsung_AC_Mode_Select *select)
      {
        mode = select;
        mode->write_state_ = [this](Mode value)
        {
          ProtocolRequest request;
          request.mode = value;
          publish_request(request);
        };
      }

      void set_water_heater_mode_select(Samsung_AC_Water_Heater_Mode_Select *select)
      {
        waterheatermode = select;
        waterheatermode->write_state_ = [this](WaterHeaterMode value)
        {
          ProtocolRequest request;
          request.waterheatermode = value;
          publish_request(request);
        };
      }

      void set_target_temperature_number(Samsung_AC_Number *number)
      {
        target_temperature = number;
        target_temperature->write_state_ = [this](float value)
        {
          ProtocolRequest request;
          request.target_temp = value;
          publish_request(request);
        };
      };

      void set_water_outlet_target_number(Samsung_AC_Number *number)
      {
        water_outlet_target = number;
        water_outlet_target->write_state_ = [this](float value)
        {
          ProtocolRequest request;
          request.water_outlet_target = value;
          publish_request(request);
        };
      };

      void set_target_water_temperature_number(Samsung_AC_Number *number)
      {
        target_water_temperature = number;
        target_water_temperature->write_state_ = [this](float value)
        {
          ProtocolRequest request;
          request.target_water_temp = value;
          publish_request(request);
        };
      };
      void set_target_temperature_zone2_number(Samsung_AC_Number *number)
      {
        target_temperature_zone2 = number;
        target_temperature_zone2->write_state_ = [this](float value)
        {
          ProtocolRequest request;
          request.target_temp_zone2 = value;
          publish_request(request);
        };
      };

      void set_fsv1012_number(Samsung_AC_Number *number)
      {
          fsv1012 = number;
          fsv1012->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv1012 = value;
              publish_request(request);
          };
      }

      void set_fsv1021_number(Samsung_AC_Number *number)
      {
          fsv1021 = number;
          fsv1021->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv1021 = value;
              publish_request(request);
          };
      }

      void set_fsv1022_number(Samsung_AC_Number *number)
      {
          fsv1022 = number;
          fsv1022->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv1022 = value;
              publish_request(request);
          };
      }

      void set_fsv1031_number(Samsung_AC_Number *number)
      {
          fsv1031 = number;
          fsv1031->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv1031 = value;
              publish_request(request);
          };
      }

      void set_fsv1032_number(Samsung_AC_Number *number)
      {
          fsv1032 = number;
          fsv1032->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv1032 = value;
              publish_request(request);
          };
      }

      void set_fsv1041_number(Samsung_AC_Number *number)
      {
          fsv1041 = number;
          fsv1041->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv1041 = value;
              publish_request(request);
          };
      }

      void set_fsv1042_number(Samsung_AC_Number *number)
      {
          fsv1042 = number;
          fsv1042->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv1042 = value;
              publish_request(request);
          };
      }

      void set_fsv1051_number(Samsung_AC_Number *number)
      {
          fsv1051 = number;
          fsv1051->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv1051 = value;
              publish_request(request);
          };
      }

      void set_fsv1052_number(Samsung_AC_Number *number)
      {
          fsv1052 = number;
          fsv1052->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv1052 = value;
              publish_request(request);
          };
      }
      void set_fsv5011_number(Samsung_AC_Number *number)
      {
          fsv5011 = number;
          fsv5011->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv5011 = value;
              publish_request(request);
          };
      }
      void set_fsv5012_number(Samsung_AC_Number *number)
      {
          fsv5012 = number;
          fsv5012->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv5012 = value;
              publish_request(request);
          };
      }
      void set_fsv5013_number(Samsung_AC_Number *number)
      {
          fsv5013 = number;
          fsv5013->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv5013 = value;
              publish_request(request);
          };
      }
      void set_fsv5014_number(Samsung_AC_Number *number)
      {
          fsv5014 = number;
          fsv5014->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv5014 = value;
              publish_request(request);
          };
      }
      void set_fsv5015_number(Samsung_AC_Number *number)
      {
          fsv5015 = number;
          fsv5015->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv5015 = value;
              publish_request(request);
          };
      }
      void set_fsv5016_number(Samsung_AC_Number *number)
      {
          fsv5016 = number;
          fsv5016->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv5016 = value;
              publish_request(request);
          };
      }
      void set_fsv5017_number(Samsung_AC_Number *number)
      {
          fsv5017 = number;
          fsv5017->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv5017 = value;
              publish_request(request);
          };
      }
      void set_fsv5018_number(Samsung_AC_Number *number)
      {
          fsv5018 = number;
          fsv5018->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv5018 = value;
              publish_request(request);
          };
      }
      void set_fsv5019_number(Samsung_AC_Number *number)
      {
          fsv5019 = number;
          fsv5019->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv5019 = value;
              publish_request(request);
          };
      }
      
      
      void set_target_offset_number(Samsung_AC_Number *number)
      {
        target_offset = number;
        target_offset->write_state_ = [this](float value)
        {
          ProtocolRequest request;
          request.target_offset = value;
          publish_request(request);
        };
      };

      void set_fsv1011_number(Samsung_AC_Number *number)
      {
        fsv1011 = number;
        fsv1011->write_state_ = [this](float value)
        {
          ProtocolRequest request;
          request.fsv1011 = value;
          publish_request(request);
        };
      };
      void set_fsv2012_number(Samsung_AC_Number *number)
      {
        fsv2012 = number;
        fsv2012->write_state_ = [this](float value)
        {
          ProtocolRequest request;
          request.fsv2012 = value;
          publish_request(request);
        };
      };
      void set_fsv2021_number(Samsung_AC_Number *number)
      {
          fsv2021 = number;
          fsv2021->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv2021 = value;
              publish_request(request);
          };
      };

      void set_fsv2022_number(Samsung_AC_Number *number)
      {
          fsv2022 = number;
          fsv2022->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv2022 = value;
              publish_request(request);
          };
      };

      void set_fsv2031_number(Samsung_AC_Number *number)
      {
          fsv2031 = number;
          fsv2031->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv2031 = value;
              publish_request(request);
          };
      };

      void set_fsv2032_number(Samsung_AC_Number *number)
      {
          fsv2032 = number;
          fsv2032->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv2032 = value;
              publish_request(request);
          };
      };

      void set_fsv2051_number(Samsung_AC_Number *number)
      {
          fsv2051 = number;
          fsv2051->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv2051 = value;
              publish_request(request);
          };
      };

      void set_fsv2052_number(Samsung_AC_Number *number)
      {
          fsv2052 = number;
          fsv2052->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv2052 = value;
              publish_request(request);
          };
      };

      void set_fsv2061_number(Samsung_AC_Number *number)
      {
          fsv2061 = number;
          fsv2061->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv2061 = value;
              publish_request(request);
          };
      };

      void set_fsv2062_number(Samsung_AC_Number *number)
      {
          fsv2062 = number;
          fsv2062->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv2062 = value;
              publish_request(request);
          };
      };

      void set_fsv2071_number(Samsung_AC_Number *number)
      {
        fsv2071 = number;
        fsv2071->write_state_ = [this](float value)
        {
          ProtocolRequest request;
          request.fsv2071 = value;
          publish_request(request);
        };
      };
      void set_fsv2072_number(Samsung_AC_Number *number)
      {
        fsv2072 = number;
        fsv2072->write_state_ = [this](float value)
        {
          ProtocolRequest request;
          request.fsv2072 = value;
          publish_request(request);
        };
      };

      void set_fsv3021_number(Samsung_AC_Number *number)
      {
          fsv3021 = number;
          fsv3021->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3021 = value;
              publish_request(request);
          };
      }

      void set_fsv3022_number(Samsung_AC_Number *number)
      {
          fsv3022 = number;
          fsv3022->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3022 = value;
              publish_request(request);
          };
      }

      void set_fsv3023_number(Samsung_AC_Number *number)
      {
          fsv3023 = number;
          fsv3023->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3023 = value;
              publish_request(request);
          };
      }

      void set_fsv3024_number(Samsung_AC_Number *number)
      {
          fsv3024 = number;
          fsv3024->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3024 = value;
              publish_request(request);
          };
      }

      void set_fsv3025_number(Samsung_AC_Number *number)
      {
          fsv3025 = number;
          fsv3025->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3025 = value;
              publish_request(request);
          };
      }

      void set_fsv3026_number(Samsung_AC_Number *number)
      {
          fsv3026 = number;
          fsv3026->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3026 = value;
              publish_request(request);
          };
      }

      void set_fsv3031_number(Samsung_AC_Number *number)
      {
          fsv3031 = number;
          fsv3031->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3031 = value;
              publish_request(request);
          };
      }

      void set_fsv3032_number(Samsung_AC_Number *number)
      {
          fsv3032 = number;
          fsv3032->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3032 = value;
              publish_request(request);
          };
      }

      void set_fsv3033_number(Samsung_AC_Number *number)
      {
          fsv3033 = number;
          fsv3033->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3033 = value;
              publish_request(request);
          };
      }

      void set_fsv3044_number(Samsung_AC_Number *number)
      {
          fsv3044 = number;
          fsv3044->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3044 = value;
              publish_request(request);
          };
      }

      void set_fsv3051_number(Samsung_AC_Number *number)
      {
          fsv3051 = number;
          fsv3051->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3051 = value;
              publish_request(request);
          };
      }

      void set_fsv3052_number(Samsung_AC_Number *number)
      {
          fsv3052 = number;
          fsv3052->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3052 = value;
              publish_request(request);
          };
      }

      void set_fsv3071_number(Samsung_AC_Number *number)
      {
          fsv3071 = number;
          fsv3071->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3071 = value;
              publish_request(request);
          };
      }

      void set_fsv3081_number(Samsung_AC_Number *number)
      {
          fsv3081 = number;
          fsv3081->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3081 = value;
              publish_request(request);
          };
      }

      void set_fsv3082_number(Samsung_AC_Number *number)
      {
          fsv3082 = number;
          fsv3082->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3082 = value;
              publish_request(request);
          };
      }

      void set_fsv3083_number(Samsung_AC_Number *number)
      {
          fsv3083 = number;
          fsv3083->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3083 = value;
              publish_request(request);
          };
      }

      void set_fsv2041_number(Samsung_AC_Number *number)
      {
          fsv2041 = number;
          fsv2041->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv2041 = value;
              publish_request(request);
          };
      }

      void set_fsv2081_number(Samsung_AC_Number *number)
      {
          fsv2081 = number;
          fsv2081->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv2081 = value;
              publish_request(request);
          };
      }

      void set_fsv2091_number(Samsung_AC_Number *number)
      {
          fsv2091 = number;
          fsv2091->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv2091 = value;
              publish_request(request);
          };
      }

      void set_fsv2092_number(Samsung_AC_Number *number)
      {
          fsv2092 = number;
          fsv2092->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv2092 = value;
              publish_request(request);
          };
      }

      void set_fsv2093_number(Samsung_AC_Number *number)
      {
          fsv2093 = number;
          fsv2093->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv2093 = value;
              publish_request(request);
          };
      }

      void set_fsv3011_number(Samsung_AC_Number *number)
      {
          fsv3011 = number;
          fsv3011->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3011 = value;
              publish_request(request);
          };
      }

      void set_fsv3041_number(Samsung_AC_Number *number)
      {
          fsv3041 = number;
          fsv3041->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3041 = value;
              publish_request(request);
          };
      }

      void set_fsv3042_number(Samsung_AC_Number *number)
      {
          fsv3042 = number;
          fsv3042->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3042 = value;
              publish_request(request);
          };
      }
      void set_fsv3043_number(Samsung_AC_Number *number)
      {
          fsv3043 = number;
          fsv3043->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3043 = value;
              publish_request(request);
          };
      }


      void set_fsv3045_number(Samsung_AC_Number *number)
      {
          fsv3045 = number;
          fsv3045->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3045 = value;
              publish_request(request);
          };
      }

      void set_fsv3046_number(Samsung_AC_Number *number)
      {
          fsv3046 = number;
          fsv3046->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3046 = value;
              publish_request(request);
          };
      }

      void set_fsv3061_number(Samsung_AC_Number *number)
      {
          fsv3061 = number;
          fsv3061->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv3061 = value;
              publish_request(request);
          };
      }

      void set_fsv4061_number(Samsung_AC_Number *number)
      {
          fsv4061 = number;
          fsv4061->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv4061 = value;
              publish_request(request);
          };
      }

      void set_fsv5022_number(Samsung_AC_Number *number)
      {
          fsv5022 = number;
          fsv5022->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv5022 = value;
              publish_request(request);
          };
      }

      void set_fsv4011_number(Samsung_AC_Number *number)
      {
          fsv4011 = number;
          fsv4011->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv4011 = value;
              publish_request(request);
          };
      }

      void set_fsv4013_number(Samsung_AC_Number *number)
      {
          fsv4013 = number;
          fsv4013->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv4013 = value;
              publish_request(request);
          };
      }

      void set_fsv4021_number(Samsung_AC_Number *number)
      {
          fsv4021 = number;
          fsv4021->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv4021 = value;
              publish_request(request);
          };
      }

      void set_fsv4022_number(Samsung_AC_Number *number)
      {
          fsv4022 = number;
          fsv4022->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv4022 = value;
              publish_request(request);
          };
      }

      void set_fsv4023_number(Samsung_AC_Number *number)
      {
          fsv4023 = number;
          fsv4023->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv4023 = value;
              publish_request(request);
          };
      }

      void set_fsv4025_number(Samsung_AC_Number *number)
      {
          fsv4025 = number;
          fsv4025->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv4025 = value;
              publish_request(request);
          };
      }

      void set_fsv4031_number(Samsung_AC_Number *number)
      {
          fsv4031 = number;
          fsv4031->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv4031 = value;
              publish_request(request);
          };
      }

      void set_fsv4032_number(Samsung_AC_Number *number)
      {
          fsv4032 = number;
          fsv4032->write_state_ = [this](float value)
          {
              ProtocolRequest request;
              request.fsv4032 = value;
              publish_request(request);
          };
      }






      void set_climate(Samsung_AC_Climate *value)
      {
        climate = value;
        climate->device = this;
      }

      void update_target_temperature(float value)
      {
        if (target_temperature != nullptr)
          target_temperature->publish_state(value);
        if (climate != nullptr)
        {
          climate->target_temperature = value;
          climate->publish_state();
        }
      }

      void update_water_outlet_target(float value)
      {
        if (water_outlet_target != nullptr)
          water_outlet_target->publish_state(value);
      }

      void update_target_water_temperature(float value)
      {
        if (target_water_temperature != nullptr)
          target_water_temperature->publish_state(value);
      }
      void update_target_temperature_zone2(float value)
      {
        if (target_temperature_zone2 != nullptr)
          target_temperature_zone2->publish_state(value);
      }
      void update_fsv1012(float value)
      {
          if (fsv1012 != nullptr)
              fsv1012->publish_state(value);
      }
      void update_fsv1021(float value)
      {
          if (fsv1021 != nullptr)
              fsv1021->publish_state(value);
      }
      void update_fsv1022(float value)
      {
          if (fsv1022 != nullptr)
              fsv1022->publish_state(value);
      }
      void update_fsv1031(float value)
      {
          if (fsv1031 != nullptr)
              fsv1031->publish_state(value);
      }
      void update_fsv1032(float value)
      {
          if (fsv1032 != nullptr)
              fsv1032->publish_state(value);
      }
      void update_fsv1041(float value)
      {
          if (fsv1041 != nullptr)
              fsv1041->publish_state(value);
      }
      void update_fsv1042(float value)
      {
          if (fsv1042 != nullptr)
              fsv1042->publish_state(value);
      }
      void update_fsv1051(float value)
      {
          if (fsv1051 != nullptr)
              fsv1051->publish_state(value);
      }
      void update_fsv1052(float value)
      {
          if (fsv1052 != nullptr)
              fsv1052->publish_state(value);
      }
      void update_fsv5011(float value)
      {
          if (fsv5011 != nullptr)
              fsv5011->publish_state(value);
      }
      void update_fsv5012(float value)
      {
          if (fsv5012 != nullptr)
              fsv5012->publish_state(value);
      }
      void update_fsv5013(float value)
      {
          if (fsv5013 != nullptr)
              fsv5013->publish_state(value);
      }
      void update_fsv5014(float value)
      {
          if (fsv5014 != nullptr)
              fsv5014->publish_state(value);
      }
      void update_fsv5015(float value)
      {
          if (fsv5015 != nullptr)
              fsv5015->publish_state(value);
      }
      void update_fsv5016(float value)
      {
          if (fsv5016 != nullptr)
              fsv5016->publish_state(value);
      }
      void update_fsv5017(float value)
      {
          if (fsv5017 != nullptr)
              fsv5017->publish_state(value);
      }
      void update_fsv5018(float value)
      {
          if (fsv5018 != nullptr)
              fsv5018->publish_state(value);
      }
      void update_fsv5019(float value)
      {
          if (fsv5019 != nullptr)
              fsv5019->publish_state(value);
      }
      
      void update_target_offset(float value)
      {
        if (target_offset != nullptr)
          target_offset->publish_state(value);
      }
      void update_fsv1011(float value)
      {
        if (fsv1011 != nullptr)
          fsv1011->publish_state(value);
      }
      void update_fsv2012(float value)
      {
        if (fsv2012 != nullptr)
          fsv2012->publish_state(value);
      }
      void update_fsv2021(float value)
      {
          if (fsv2021 != nullptr)
              fsv2021->publish_state(value);
      }

      void update_fsv2022(float value)
      {
          if (fsv2022 != nullptr)
              fsv2022->publish_state(value);
      }

      void update_fsv2031(float value)
      {
          if (fsv2031 != nullptr)
              fsv2031->publish_state(value);
      }

      void update_fsv2032(float value)
      {
          if (fsv2032 != nullptr)
              fsv2032->publish_state(value);
      }

      void update_fsv2051(float value)
      {
          if (fsv2051 != nullptr)
              fsv2051->publish_state(value);
      }

      void update_fsv2052(float value)
      {
          if (fsv2052 != nullptr)
              fsv2052->publish_state(value);
      }

      void update_fsv2061(float value)
      {
          if (fsv2061 != nullptr)
              fsv2061->publish_state(value);
      }

      void update_fsv2062(float value)
      {
          if (fsv2062 != nullptr)
              fsv2062->publish_state(value);
      }


      void update_fsv2071(float value)
      {
        if (fsv2071 != nullptr)
          fsv2071->publish_state(value);
      }
      void update_fsv2072(float value)
      {
        if (fsv2072 != nullptr)
          fsv2072->publish_state(value);
      }

      void update_fsv3021(float value)
      {
          if (fsv3021 != nullptr)
              fsv3021->publish_state(value);
      }

      void update_fsv3022(float value)
      {
          if (fsv3022 != nullptr)
              fsv3022->publish_state(value);
      }

      void update_fsv3023(float value)
      {
          if (fsv3023 != nullptr)
              fsv3023->publish_state(value);
      }

      void update_fsv3024(float value)
      {
          if (fsv3024 != nullptr)
              fsv3024->publish_state(value);
      }

      void update_fsv3025(float value)
      {
          if (fsv3025 != nullptr)
              fsv3025->publish_state(value);
      }

      void update_fsv3026(float value)
      {
          if (fsv3026 != nullptr)
              fsv3026->publish_state(value);
      }

      void update_fsv3031(float value)
      {
          if (fsv3031 != nullptr)
              fsv3031->publish_state(value);
      }

      void update_fsv3032(float value)
      {
          if (fsv3032 != nullptr)
              fsv3032->publish_state(value);
      }

      void update_fsv3033(float value)
      {
          if (fsv3033 != nullptr)
              fsv3033->publish_state(value);
      }

      void update_fsv3044(float value)
      {
          if (fsv3044 != nullptr)
              fsv3044->publish_state(value);
      }

      void update_fsv3051(float value)
      {
          if (fsv3051 != nullptr)
              fsv3051->publish_state(value);
      }

      void update_fsv3052(float value)
      {
          if (fsv3052 != nullptr)
              fsv3052->publish_state(value);
      }

      void update_fsv3071(float value)
      {
          if (fsv3071 != nullptr)
              fsv3071->publish_state(value);
      }

      void update_fsv3081(float value)
      {
          if (fsv3081 != nullptr)
              fsv3081->publish_state(value);
      }

      void update_fsv3082(float value)
      {
          if (fsv3082 != nullptr)
              fsv3082->publish_state(value);
      }

      void update_fsv3083(float value)
      {
          if (fsv3083 != nullptr)
              fsv3083->publish_state(value);
      }

      void update_fsv2041(float value)
      {
          if (fsv2041 != nullptr)
              fsv2041->publish_state(value);
      }

      void update_fsv2081(float value)
      {
          if (fsv2081 != nullptr)
              fsv2081->publish_state(value);
      }

      void update_fsv2091(float value)
      {
          if (fsv2091 != nullptr)
              fsv2091->publish_state(value);
      }

      void update_fsv2092(float value)
      {
          if (fsv2092 != nullptr)
              fsv2092->publish_state(value);
      }

      void update_fsv2093(float value)
      {
          if (fsv2093 != nullptr)
              fsv2093->publish_state(value);
      }

      void update_fsv3011(float value)
      {
          if (fsv3011 != nullptr)
              fsv3011->publish_state(value);
      }

      void update_fsv3041(float value)
      {
          if (fsv3041 != nullptr)
              fsv3041->publish_state(value);
      }

      void update_fsv3042(float value)
      {
          if (fsv3042 != nullptr)
              fsv3042->publish_state(value);
      }
      void update_fsv3043(float value)
      {
          if (fsv3043 != nullptr)
              fsv3043->publish_state(value);
      }

      void update_fsv3045(float value)
      {
          if (fsv3045 != nullptr)
              fsv3045->publish_state(value);
      }

      void update_fsv3046(float value)
      {
          if (fsv3046 != nullptr)
              fsv3046->publish_state(value);
      }

      void update_fsv3061(float value)
      {
          if (fsv3061 != nullptr)
              fsv3061->publish_state(value);
      }

      void update_fsv4061(float value)
      {
          if (fsv4061 != nullptr)
              fsv4061->publish_state(value);
      }

      void update_fsv5022(float value)
      {
          if (fsv5022 != nullptr)
              fsv5022->publish_state(value);
      }

      void update_fsv4011(float value)
      {
          if (fsv4011 != nullptr)
              fsv4011->publish_state(value);
      }

      void update_fsv4013(float value)
      {
          if (fsv4013 != nullptr)
              fsv4013->publish_state(value);
      }

      void update_fsv4021(float value)
      {
          if (fsv4021 != nullptr)
              fsv4021->publish_state(value);
      }

      void update_fsv4022(float value)
      {
          if (fsv4022 != nullptr)
              fsv4022->publish_state(value);
      }

      void update_fsv4023(float value)
      {
          if (fsv4023 != nullptr)
              fsv4023->publish_state(value);
      }

      void update_fsv4025(float value)
      {
          if (fsv4025 != nullptr)
              fsv4025->publish_state(value);
      }

      void update_fsv4031(float value)
      {
          if (fsv4031 != nullptr)
              fsv4031->publish_state(value);
      }

      void update_fsv4032(float value)
      {
          if (fsv4032 != nullptr)
              fsv4032->publish_state(value);
      }



      optional<bool> _cur_power;
      optional<bool> _cur_power_zone2;
      optional<bool> _cur_vacation;
      optional<bool> _cur_automatic_cleaning;
      optional<bool> _cur_water_heater_power;
      optional<Mode> _cur_mode;
      optional<WaterHeaterMode> _cur_water_heater_mode;

      void update_power(bool value)
      {
        _cur_power = value;
        if (power != nullptr)
          power->publish_state(value);
        if (climate != nullptr)
          calc_and_publish_mode();
      }
      void update_power_zone2(bool value)
      {
        _cur_power_zone2 = value;
        if (power_zone2 != nullptr)
          power_zone2->publish_state(value);
        if (climate != nullptr)
          calc_and_publish_mode();
      }
      void update_vacation(bool value)
      {
        _cur_vacation = value;
        if (vacation != nullptr)
          vacation->publish_state(value);
      }

      void update_automatic_cleaning(bool value)
      {
        _cur_automatic_cleaning = value;
        if (automatic_cleaning != nullptr)
          automatic_cleaning->publish_state(value);
        if (climate != nullptr)
          calc_and_publish_mode();
      }

      void update_water_heater_power(bool value)
      {
        _cur_water_heater_power = value;
        if (water_heater_power != nullptr)
          water_heater_power->publish_state(value);
      }

      void update_mode(Mode value)
      {
        _cur_mode = value;
        if (mode != nullptr)
          mode->publish_state_(value);
        if (climate != nullptr)
          calc_and_publish_mode();
      }

      void update_water_heater_mode(WaterHeaterMode value)
      {
        _cur_water_heater_mode = value;
        if (waterheatermode != nullptr)
          waterheatermode->publish_state_(value);
      }

      void update_fanmode(FanMode value)
      {
        if (climate != nullptr)
        {
          climate->fan_mode = fanmode_to_climatefanmode(value);

          auto fanmode = fanmode_to_climatefanmode(value);
          if (fanmode.has_value())
          {
            climate->fan_mode = fanmode;
            climate->custom_fan_mode.reset();
          }
          else
          {
            climate->fan_mode.reset();
            climate->custom_fan_mode = fanmode_to_custom_climatefanmode(value);
          }
          climate->publish_state();
        }
      }

      void update_altmode(AltMode value)
      {
        if (climate != nullptr)
        {
          auto supported = get_supported_alt_modes();
          auto mode = std::find_if(supported->begin(), supported->end(), [&value](const AltModeDesc &x)
                                   { return x.value == value; });
          if (mode == supported->end())
          {
            ESP_LOGW(TAG, "Unsupported alt_mode %d", value);
            return;
          }

          auto preset = altmodename_to_preset(mode->name);
          if (preset)
          {
            climate->preset = preset.value();
            climate->custom_preset.reset();
          }
          else
          {
            climate->preset.reset();
            climate->custom_preset = mode->name;
          }
          climate->publish_state();
        }
      }

      void update_swing_vertical(bool value)
      {
        if (climate != nullptr)
        {
          update_swing(climate->swing_mode, 1, value);
        }
      }

      void update_swing_horizontal(bool value)
      {
        if (climate != nullptr)
        {
          update_swing(climate->swing_mode, 2, value);
        }
      }

      void publish_request(ProtocolRequest &request)
      {
        protocol->publish_request(target, address, request);
      }

      bool supports_horizontal_swing()
      {
        return supports_horizontal_swing_;
      }

      bool supports_vertical_swing()
      {
        return supports_vertical_swing_;
      }

      void set_supports_horizontal_swing(bool value)
      {
        supports_horizontal_swing_ = value;
      }

      void set_supports_vertical_swing(bool value)
      {
        supports_vertical_swing_ = value;
      }

      void add_alt_mode(const AltModeName &name, AltMode value)
      {
        AltModeDesc desc;
        desc.name = name;
        desc.value = value;
        alt_modes.push_back(std::move(desc));
      }

      const std::vector<AltModeDesc> *get_supported_alt_modes()
      {
        return &alt_modes;
      }

      void set_room_temperature_offset(float value)
      {
        room_temperature_offset = value;
      }

      void protocol_update(MessageTarget *target)
      {
        if (protocol != nullptr)
        {
          protocol->protocol_update(target);
        }
      }

    protected:
      bool supports_horizontal_swing_{false};
      bool supports_vertical_swing_{false};
      std::vector<AltModeDesc> alt_modes;

      Protocol *protocol{nullptr};
      MessageTarget *target{nullptr};

      climate::ClimateSwingMode combine(climate::ClimateSwingMode climateSwingMode, uint8_t mask, bool value)
      {
        uint8_t swingMode = static_cast<uint8_t>(climateswingmode_to_swingmode(climateSwingMode));
        return swingmode_to_climateswingmode(static_cast<SwingMode>(value ? (swingMode | mask) : (swingMode & ~mask)));
      }

      void calc_and_publish_mode()
      {
        if (!_cur_power.has_value())
          return;
        if (!_cur_power_zone2.has_value())
          return;
        if (!_cur_mode.has_value())
          return;

        climate->mode = climate::ClimateMode::CLIMATE_MODE_OFF;
        if (_cur_power.value() == true)
        {
          auto opt = mode_to_climatemode(_cur_mode.value());
          if (opt.has_value())
            climate->mode = opt.value();
        }

        climate->publish_state();
      }
    };
  } // namespace samsung_ac
} // namespace esphome
