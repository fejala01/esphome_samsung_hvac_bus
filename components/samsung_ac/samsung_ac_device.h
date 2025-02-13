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
      sensor::Sensor *outdoor_water_temperature{nullptr};
      sensor::Sensor *waterflow{nullptr};
      sensor::Sensor *compressor_frequency{nullptr};
      sensor::Sensor *energy_produced_lifetime{nullptr};
      sensor::Sensor *base_heater{nullptr};
      sensor::Sensor *backup_heater{nullptr};
      sensor::Sensor *service{nullptr};
      sensor::Sensor *deice_mode{nullptr};
      sensor::Sensor *deice_status{nullptr};
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
      //Sensoren
      sensor::Sensor *fsv1011{nullptr};
      sensor::Sensor *fsv1012{nullptr};
      sensor::Sensor *fsv1021{nullptr};
      sensor::Sensor *fsv1022{nullptr};
      sensor::Sensor *fsv1031{nullptr};
      sensor::Sensor *fsv1032{nullptr};
      sensor::Sensor *fsv1051{nullptr};
      sensor::Sensor *fsv1052{nullptr};
      sensor::Sensor *fsv2011{nullptr};
      sensor::Sensor *fsv2012{nullptr};
      sensor::Sensor *fsv2021{nullptr};
      sensor::Sensor *fsv2022{nullptr};
      sensor::Sensor *fsv2031{nullptr};
      sensor::Sensor *fsv2032{nullptr};
      sensor::Sensor *fsv2051{nullptr};
      sensor::Sensor *fsv2052{nullptr};
      sensor::Sensor *fsv2041{nullptr};
      sensor::Sensor *fsv2081{nullptr};
      sensor::Sensor *fsv2093{nullptr};
      sensor::Sensor *fsv3022{nullptr};
      sensor::Sensor *fsv3023{nullptr};
      sensor::Sensor *fsv3031{nullptr};
      sensor::Sensor *fsv3032{nullptr};
      sensor::Sensor *fsv3033{nullptr};
      sensor::Sensor *fsv3041{nullptr};



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
      void set_outdoor_water_temperature_sensor(sensor::Sensor *sensor)
      {
        outdoor_water_temperature = sensor;
      }
      void set_waterflow_sensor(sensor::Sensor *sensor)
      {
        waterflow = sensor;
      }
      void set_compressor_frequency_sensor(sensor::Sensor *sensor)
      {
        compressor_frequency = sensor;
      }
      void set_energy_produced_lifetime_sensor(sensor::Sensor *sensor)
      {
        energy_produced_lifetime = sensor;
      }
      void set_base_heater_sensor(sensor::Sensor *sensor)
      {
        base_heater = sensor;
      }
      void set_backup_heater_sensor(sensor::Sensor *sensor)
      {
        backup_heater = sensor;
      }
      void set_service_sensor(sensor::Sensor *sensor)
      {
        service = sensor;
      }
      void set_deice_status_sensor(sensor::Sensor *sensor)
      {
        deice_status = sensor;
      }
      void set_deice_mode_sensor(sensor::Sensor *sensor)
      {
        deice_mode = sensor;
      }

      //Sensoren
      void set_fsv1011_sensor(sensor::Sensor *sensor)
      {
        fsv1011 = sensor;
      }
      void set_fsv1012_sensor(sensor::Sensor *sensor)
      {
        fsv1012 = sensor;
      }
      void set_fsv1021_sensor(sensor::Sensor *sensor)
      {
        fsv1021 = sensor;
      }
      void set_fsv1022_sensor(sensor::Sensor *sensor)
      {
        fsv1022 = sensor;
      }
      void set_fsv1031_sensor(sensor::Sensor *sensor)
      {
        fsv1031 = sensor;
      }
      void set_fsv1032_sensor(sensor::Sensor *sensor)
      {
        fsv1032 = sensor;
      }
      void set_fsv1051_sensor(sensor::Sensor *sensor)
      {
        fsv1051 = sensor;
      }
      void set_fsv1052_sensor(sensor::Sensor *sensor)
      {
        fsv1052 = sensor;
      }
      void set_fsv2011_sensor(sensor::Sensor *sensor)
      {
        fsv2011 = sensor;
      }
      void set_fsv2012_sensor(sensor::Sensor *sensor)
      {
        fsv2012 = sensor;
      }
      void set_fsv2021_sensor(sensor::Sensor *sensor)
      {
        fsv2021 = sensor;
      }
      void set_fsv2022_sensor(sensor::Sensor *sensor)
      {
        fsv2022 = sensor;
      }
      void set_fsv2031_sensor(sensor::Sensor *sensor)
      {
        fsv2031 = sensor;
      }
      void set_fsv2032_sensor(sensor::Sensor *sensor)
      {
        fsv2032 = sensor;
      }
      void set_fsv2051_sensor(sensor::Sensor *sensor)
      {
        fsv2051 = sensor;
      }
      void set_fsv2052_sensor(sensor::Sensor *sensor)
      {
        fsv2052 = sensor;
      }
      void set_fsv2041_sensor(sensor::Sensor *sensor)
      {
        fsv2041 = sensor;
      }
      void set_fsv2081_sensor(sensor::Sensor *sensor)
      {
        fsv2081 = sensor;
      }
      void set_fsv2093_sensor(sensor::Sensor *sensor)
      {
        fsv2093 = sensor;
      }
      void set_fsv3022_sensor(sensor::Sensor *sensor)
      {
        fsv3022 = sensor;
      }
      void set_fsv3023_sensor(sensor::Sensor *sensor)
      {
        fsv3023 = sensor;
      }
      void set_fsv3031_sensor(sensor::Sensor *sensor)
      {
        fsv3031 = sensor;
      }
      void set_fsv3032_sensor(sensor::Sensor *sensor)
      {
        fsv3032 = sensor;
      }
      void set_fsv3033_sensor(sensor::Sensor *sensor)
      {
        fsv3033 = sensor;
      }
      void set_fsv3041_sensor(sensor::Sensor *sensor)
      {
        fsv3041 = sensor;
      }



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
      void update_target_offset(float value)
      {
        if (target_offset != nullptr)
          target_offset->publish_state(value);
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
