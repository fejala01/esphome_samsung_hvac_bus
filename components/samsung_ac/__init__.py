import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart, sensor, switch, select, number, climate
from esphome.const import (
    CONF_ID,
    DEVICE_CLASS_TEMPERATURE,
    STATE_CLASS_MEASUREMENT,
    STATE_CLASS_TOTAL_INCREASING,
    DEVICE_CLASS_ENERGY,
    DEVICE_CLASS_POWER,
    DEVICE_CLASS_FREQUENCY, 
    DEVICE_CLASS_HUMIDITY,
    DEVICE_CLASS_VOLTAGE,
    DEVICE_CLASS_CURRENT,
    DEVICE_CLASS_PRESSURE,
    UNIT_CELSIUS,
    UNIT_PERCENT,
    UNIT_WATT,
    UNIT_VOLT,
    UNIT_AMPERE,
    CONF_UNIT_OF_MEASUREMENT,
    CONF_DEVICE_CLASS,
    CONF_FILTERS,
)
from esphome.core import CORE, Lambda

CODEOWNERS = ["matthias882", "lanwin", "omerfaruk-aran"]
DEPENDENCIES = ["uart"]
AUTO_LOAD = ["sensor", "switch", "select", "number", "climate"]
MULTI_CONF = False

CONF_SAMSUNG_AC_ID = "samsung_ac_id"

samsung_ac = cg.esphome_ns.namespace("samsung_ac")
Samsung_AC = samsung_ac.class_("Samsung_AC", cg.PollingComponent, uart.UARTDevice)
Samsung_AC_Device = samsung_ac.class_("Samsung_AC_Device")
Samsung_AC_Switch = samsung_ac.class_("Samsung_AC_Switch", switch.Switch)
Samsung_AC_Mode_Select = samsung_ac.class_("Samsung_AC_Mode_Select", select.Select)
Samsung_AC_Water_Heater_Mode_Select = samsung_ac.class_(
    "Samsung_AC_Water_Heater_Mode_Select", select.Select
)
Samsung_AC_Number = samsung_ac.class_("Samsung_AC_Number", number.Number)
Samsung_AC_Climate = samsung_ac.class_("Samsung_AC_Climate", climate.Climate)

# not sure why select.select_schema did not work yet
SELECT_MODE_SCHEMA = select.select_schema(Samsung_AC_Mode_Select)
SELECT_WATER_HEATER_MODE_SCHEMA = select.select_schema(
    Samsung_AC_Water_Heater_Mode_Select
)

NUMBER_SCHEMA = number.NUMBER_SCHEMA.extend(
    {cv.GenerateID(): cv.declare_id(Samsung_AC_Number)}
)

CLIMATE_SCHEMA = climate.CLIMATE_SCHEMA.extend(
    {cv.GenerateID(): cv.declare_id(Samsung_AC_Climate)}
)

CONF_DEVICE_ID = "samsung_ac_device_id"
CONF_DEVICE_ADDRESS = "address"
CONF_DEVICE_ROOM_TEMPERATURE = "room_temperature"
CONF_DEVICE_ROOM_TEMPERATURE_OFFSET = "room_temperature_offset"
CONF_DEVICE_TARGET_TEMPERATURE = "target_temperature"
CONF_DEVICE_WATER_OUTLET_TARGET = "water_outlet_target"
CONF_DEVICE_OUTDOOR_TEMPERATURE = "outdoor_temperature"
CONF_DEVICE_INDOOR_EVA_IN_TEMPERATURE = "indoor_eva_in_temperature"
CONF_DEVICE_INDOOR_EVA_OUT_TEMPERATURE = "indoor_eva_out_temperature"
CONF_DEVICE_WATER_TEMPERATURE = "water_temperature"
CONF_DEVICE_WATER_TARGET_TEMPERATURE = "water_target_temperature"
CONF_DEVICE_POWER = "power"
CONF_DEVICE_POWER_ZONE2 = "power_zone2"
CONF_DEVICE_VACATION = "vacation"
CONF_DEVICE_TARGET_TEMPERATURE_ZONE2 = "target_temperature_zone2"
CONF_DEVICE_AUTOMATIC_CLEANING = "automatic_cleaning"
CONF_DEVICE_WATER_HEATER_POWER = "water_heater_power"
CONF_DEVICE_MODE = "mode"
CONF_DEVICE_WATER_HEATER_MODE = "water_heater_mode"
CONF_DEVICE_CLIMATE = "climate"
CONF_DEVICE_ROOM_HUMIDITY = "room_humidity"
CONF_DEVICE_CUSTOM = "custom_sensor"
CONF_DEVICE_CUSTOM_MESSAGE = "message"
CONF_DEVICE_CUSTOM_RAW_FILTERS = "raw_filters"
CONF_DEVICE_ERROR_CODE = "error_code"
CONF_DEVICE_OUT_CONTROL_WATTMETER_ALL_UNIT_ACCUM = "outdoor_instantaneous_power"
CONF_DEVICE_OUT_CONTROL_WATTMETER_1W_1MIN_SUM = "outdoor_cumulative_energy"
CONF_DEVICE_OUT_SENSOR_CT1 = "outdoor_current"
CONF_DEVICE_OUT_SENSOR_VOLTAGE = "outdoor_voltage"
CONF_DEVICE_TARGET_OFFSET = "target_offset"

#ZUSATZ SENSOREN
CONF_DEVICE_EVI_BYPASS_VALVE = "evi_bypass_valve"
CONF_DEVICE_DISCHARGE_TEMP = "discharge_temp"
CONF_DEVICE_COMPRESSOR_STATUS = "compressor_status"
CONF_DEVICE_COOLANT = "coolant"
CONF_DEVICE_OPERATION_MODE_EXT = "operation_mode_ext"
CONF_DEVICE_OPERATION_MODE_REAL = "operation_mode_real"
CONF_DEVICE_WATER_PRESSURE = "water_pressure"
CONF_DEVICE_3WAY_VALVE = "3way_valve"
CONF_DEVICE_TEMP_MIXING_VALVE = "temp_mixing_valve"
CONF_DEVICE_WATER_TEMPERATURE_OUT = "water_temperature_out"
CONF_DEVICE_DEICE_STATUS = "deice_status"
CONF_DEVICE_DEICE_MODE = "deice_mode"
CONF_DEVICE_SERVICE = "service"
CONF_DEVICE_BACKUP_HEATER = "backup_heater"
CONF_DEVICE_BOOSTER_HEATER = "booster_heater"
CONF_DEVICE_BASE_HEATER = "base_heater"
CONF_DEVICE_ENERGY_PRODUCED_LIFETIME = "energy_produced_lifetime"
CONF_DEVICE_ENERGY_PRODUCED_NOW = "energy_produced_now"
CONF_DEVICE_COMPRESSOR_FREQUENCY = "compressor_frequency"
CONF_DEVICE_COMPRESSOR_FREQUENCY_TARGET = "compressor_frequency_target"
CONF_DEVICE_COMPRESSOR_FREQUENCY_ORDER = "compressor_frequency_order"
CONF_DEVICE_WATERFLOW = "waterflow"
CONF_DEVICE_WATERPUMP_PWM = "waterpump_pwm"
CONF_DEVICE_VENTILATOR = "ventilator"
CONF_DEVICE_CURRENT_TEMP_ZONE1 = "current_temp_zone1"
CONF_DEVICE_CURRENT_TEMP_ZONE2 = "current_temp_zone2"
CONF_DEVICE_FSV1011 = "fsv1011"
CONF_DEVICE_FSV1012 = "fsv1012"
CONF_DEVICE_FSV1021 = "fsv1021"
CONF_DEVICE_FSV1022 = "fsv1022"
CONF_DEVICE_FSV1031 = "fsv1031"
CONF_DEVICE_FSV1032 = "fsv1032"
CONF_DEVICE_FSV1041 = "fsv1041"
CONF_DEVICE_FSV1042 = "fsv1042"
CONF_DEVICE_FSV1051 = "fsv1051"
CONF_DEVICE_FSV1052 = "fsv1052"
CONF_DEVICE_FSV5011 = "fsv5011"
CONF_DEVICE_FSV5012 = "fsv5012"
CONF_DEVICE_FSV5013 = "fsv5013"
CONF_DEVICE_FSV5014 = "fsv5014"
CONF_DEVICE_FSV5015 = "fsv5015"
CONF_DEVICE_FSV5016 = "fsv5016"
CONF_DEVICE_FSV5017 = "fsv5017"
CONF_DEVICE_FSV5018 = "fsv5018"
CONF_DEVICE_FSV5019 = "fsv5019"
CONF_DEVICE_FSV2012 = "fsv2012"
CONF_DEVICE_FSV2021 = "fsv2021"
CONF_DEVICE_FSV2022 = "fsv2022"
CONF_DEVICE_FSV2031 = "fsv2031"
CONF_DEVICE_FSV2032 = "fsv2032"
CONF_DEVICE_FSV2051 = "fsv2051"
CONF_DEVICE_FSV2052 = "fsv2052"
CONF_DEVICE_FSV2061 = "fsv2061"
CONF_DEVICE_FSV2062 = "fsv2062"
CONF_DEVICE_FSV2071 = "fsv2071"
CONF_DEVICE_FSV2072 = "fsv2072"

CONF_DEVICE_FSV2041 = "fsv2041"
CONF_DEVICE_FSV2081 = "fsv2081"
CONF_DEVICE_FSV2091 = "fsv2091"
CONF_DEVICE_FSV2092 = "fsv2092"
CONF_DEVICE_FSV2093 = "fsv2093"
CONF_DEVICE_FSV3011 = "fsv3011"
CONF_DEVICE_FSV3041 = "fsv3041"
CONF_DEVICE_FSV3042 = "fsv3042"
CONF_DEVICE_FSV3043 = "fsv3043"
CONF_DEVICE_FSV3045 = "fsv3045"
CONF_DEVICE_FSV3046 = "fsv3046"
CONF_DEVICE_FSV3061 = "fsv3061"
CONF_DEVICE_FSV4061 = "fsv4061"
CONF_DEVICE_FSV5022 = "fsv5022"

CONF_DEVICE_FSV3021 = "fsv3021"
CONF_DEVICE_FSV3022 = "fsv3022"
CONF_DEVICE_FSV3023 = "fsv3023"
CONF_DEVICE_FSV3024 = "fsv3024"
CONF_DEVICE_FSV3025 = "fsv3025"
CONF_DEVICE_FSV3026 = "fsv3026"
CONF_DEVICE_FSV3031 = "fsv3031"
CONF_DEVICE_FSV3032 = "fsv3032"
CONF_DEVICE_FSV3033 = "fsv3033"
CONF_DEVICE_FSV3044 = "fsv3044"
CONF_DEVICE_FSV3051 = "fsv3051"
CONF_DEVICE_FSV3052 = "fsv3052"
CONF_DEVICE_FSV3071 = "fsv3071"
CONF_DEVICE_FSV3081 = "fsv3081"
CONF_DEVICE_FSV3082 = "fsv3082"
CONF_DEVICE_FSV3083 = "fsv3083"

CONF_DEVICE_FSV4011 = "fsv4011"

CONF_DEVICE_FSV4013 = "fsv4013"
CONF_DEVICE_FSV4021 = "fsv4021"
CONF_DEVICE_FSV4022 = "fsv4022"
CONF_DEVICE_FSV4023 = "fsv4023"

CONF_DEVICE_FSV4025 = "fsv4025"
CONF_DEVICE_FSV4031 = "fsv4031"
CONF_DEVICE_FSV4032 = "fsv4032"




CONF_CAPABILITIES = "capabilities"
CONF_CAPABILITIES_HORIZONTAL_SWING = "horizontal_swing"
CONF_CAPABILITIES_VERTICAL_SWING = "vertical_swing"

CONF_PRESETS = "presets"
CONF_PRESET_NAME = "name"
CONF_PRESET_ENABLED = "enabled"
CONF_PRESET_VALUE = "value"


def preset_entry(name: str, value: int, displayName: str):
    return (
        cv.Optional(name, default=False),
        cv.Any(
            cv.boolean,
            cv.All(
                {
                    cv.Optional(CONF_PRESET_ENABLED, default=False): cv.boolean,
                    cv.Optional(CONF_PRESET_NAME, default=displayName): cv.string,
                    cv.Optional(CONF_PRESET_VALUE, default=value): cv.int_,
                }
            ),
        ),
    )


PRESETS = {
    "sleep": {"value": 1, "displayName": "Sleep"},
    "quiet": {"value": 2, "displayName": "Quiet"},
    "fast": {"value": 3, "displayName": "Fast"},
    "longreach": {"value": 6, "displayName": "LongReach"},
    "eco": {"value": 7, "displayName": "Eco"},
    "windfree": {"value": 9, "displayName": "WindFree"},
}

CAPABILITIES_SCHEMA = cv.Schema(
    {
        cv.Optional(CONF_CAPABILITIES_HORIZONTAL_SWING, default=False): cv.boolean,
        cv.Optional(CONF_CAPABILITIES_VERTICAL_SWING, default=False): cv.boolean,
        cv.Optional(CONF_PRESETS): cv.Schema(
            dict(
                [
                    preset_entry(
                        name, PRESETS[name]["value"], PRESETS[name]["displayName"]
                    )
                    for name in PRESETS
                ]
            )
        ),
    }
)

CUSTOM_SENSOR_SCHEMA = sensor.sensor_schema().extend(
    {
        cv.Required(CONF_DEVICE_CUSTOM_MESSAGE): cv.hex_int,
    }
)


def custom_sensor_schema(
    message: int,
    unit_of_measurement: str = sensor._UNDEF,
    icon: str = sensor._UNDEF,
    accuracy_decimals: int = sensor._UNDEF,
    device_class: str = sensor._UNDEF,
    state_class: str = sensor._UNDEF,
    entity_category: str = sensor._UNDEF,
    raw_filters=[],
):
    return sensor.sensor_schema(
        unit_of_measurement=unit_of_measurement,
        icon=icon,
        accuracy_decimals=accuracy_decimals,
        device_class=device_class,
        state_class=state_class,
        entity_category=entity_category,
    ).extend(
        {
            cv.Optional(CONF_DEVICE_CUSTOM_MESSAGE, default=message): cv.hex_int,
            cv.Optional(
                CONF_DEVICE_CUSTOM_RAW_FILTERS, default=raw_filters
            ): sensor.validate_filters,
        }
    )


def temperature_sensor_schema(message: int):
    return custom_sensor_schema(
        message=message,
        unit_of_measurement=UNIT_CELSIUS,
        accuracy_decimals=1,
        device_class=DEVICE_CLASS_TEMPERATURE,
        state_class=STATE_CLASS_MEASUREMENT,
        raw_filters=[{"lambda": Lambda("return (int16_t)x;")}, {"multiply": 0.1}],
    )


def humidity_sensor_schema(message: int):
    return custom_sensor_schema(
        message=message,
        unit_of_measurement=UNIT_PERCENT,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_HUMIDITY,
        state_class=STATE_CLASS_MEASUREMENT,
    )


def error_code_sensor_schema(message: int):
    return custom_sensor_schema(
        message=message,
        unit_of_measurement="",
        accuracy_decimals=0,
        icon="mdi:alert",
        entity_category="diagnostic",
    )
def ventilator_sensor_schema(message: int):
    return custom_sensor_schema(
        message=message,
        unit_of_measurement="rpm",
        accuracy_decimals=0,
        icon="mdi:fan",
        state_class=STATE_CLASS_MEASUREMENT,
    )
def waterpump_pwm_sensor_schema(message: int):
    return custom_sensor_schema(
        message=message,
        unit_of_measurement="%",
        accuracy_decimals=0,
        icon="mdi:water-pump",
        state_class=STATE_CLASS_MEASUREMENT,
    )


DEVICE_SCHEMA = cv.Schema(
    {
        cv.GenerateID(CONF_DEVICE_ID): cv.declare_id(Samsung_AC_Device),
        cv.Optional(CONF_CAPABILITIES): CAPABILITIES_SCHEMA,
        cv.Required(CONF_DEVICE_ADDRESS): cv.string,
        cv.Optional(CONF_DEVICE_ROOM_TEMPERATURE): sensor.sensor_schema(
            unit_of_measurement=UNIT_CELSIUS,
            accuracy_decimals=1,
            device_class=DEVICE_CLASS_TEMPERATURE,
            state_class=STATE_CLASS_MEASUREMENT,
        ),
        cv.Optional(CONF_DEVICE_CURRENT_TEMP_ZONE1): sensor.sensor_schema(
            unit_of_measurement=UNIT_CELSIUS,
            accuracy_decimals=1,
            device_class=DEVICE_CLASS_TEMPERATURE,
            state_class=STATE_CLASS_MEASUREMENT,
        ),
        cv.Optional(CONF_DEVICE_WATER_TEMPERATURE_OUT): sensor.sensor_schema(
            unit_of_measurement=UNIT_CELSIUS,
            accuracy_decimals=1,
            device_class=DEVICE_CLASS_TEMPERATURE,
            state_class=STATE_CLASS_MEASUREMENT,
        ),
        cv.Optional(CONF_DEVICE_DISCHARGE_TEMP): sensor.sensor_schema(
            unit_of_measurement=UNIT_CELSIUS,
            accuracy_decimals=1,
            device_class=DEVICE_CLASS_TEMPERATURE,
            state_class=STATE_CLASS_MEASUREMENT,
        ),
        cv.Optional(CONF_DEVICE_WATER_PRESSURE): sensor.sensor_schema(
            unit_of_measurement="bar",
            accuracy_decimals=1,
            device_class=DEVICE_CLASS_PRESSURE,
            state_class=STATE_CLASS_MEASUREMENT,
        ),
        cv.Optional(CONF_DEVICE_TEMP_MIXING_VALVE): sensor.sensor_schema(
            unit_of_measurement=UNIT_CELSIUS,
            accuracy_decimals=1,
            device_class=DEVICE_CLASS_TEMPERATURE,
            state_class=STATE_CLASS_MEASUREMENT,
        ),
        cv.Optional(CONF_DEVICE_3WAY_VALVE): sensor.sensor_schema(
            icon="mdi:valve",
        ),
        cv.Optional(CONF_DEVICE_OUTDOOR_TEMPERATURE): sensor.sensor_schema(
            unit_of_measurement=UNIT_CELSIUS,
            accuracy_decimals=1,
            device_class=DEVICE_CLASS_TEMPERATURE,
            state_class=STATE_CLASS_MEASUREMENT,
        ),
        cv.Optional(CONF_DEVICE_WATERFLOW): sensor.sensor_schema(
            unit_of_measurement="L/min",
            accuracy_decimals=1,
            icon="mdi:water-pump",
            state_class=STATE_CLASS_MEASUREMENT,
        ),
        cv.Optional(CONF_DEVICE_COOLANT): sensor.sensor_schema(
            unit_of_measurement="-",
            accuracy_decimals=0,
            icon="mdi:car-coolant-level",
            device_class=DEVICE_CLASS_TEMPERATURE,
            state_class=STATE_CLASS_MEASUREMENT,
        ),
        cv.Optional(CONF_DEVICE_COMPRESSOR_FREQUENCY): sensor.sensor_schema(
            unit_of_measurement="Hz",
            accuracy_decimals=0,
            device_class=DEVICE_CLASS_FREQUENCY,
            state_class=STATE_CLASS_MEASUREMENT,
            icon="mdi:engine",
        ),
        cv.Optional(CONF_DEVICE_COMPRESSOR_FREQUENCY_ORDER): sensor.sensor_schema(
            unit_of_measurement="Hz",
            accuracy_decimals=0,
            device_class=DEVICE_CLASS_FREQUENCY,
            state_class=STATE_CLASS_MEASUREMENT,
            icon="mdi:engine",
        ),
        cv.Optional(CONF_DEVICE_COMPRESSOR_FREQUENCY_TARGET): sensor.sensor_schema(
            unit_of_measurement="Hz",
            accuracy_decimals=0,
            device_class=DEVICE_CLASS_FREQUENCY,
            state_class=STATE_CLASS_MEASUREMENT,
            icon="mdi:engine",
        ),
        cv.Optional(CONF_DEVICE_ENERGY_PRODUCED_LIFETIME): sensor.sensor_schema(
            unit_of_measurement="kWh",
            accuracy_decimals=3,
            device_class=DEVICE_CLASS_ENERGY,
            state_class=STATE_CLASS_MEASUREMENT,
            icon="mdi:counter",
        ),
        cv.Optional(CONF_DEVICE_ENERGY_PRODUCED_NOW): sensor.sensor_schema(
            unit_of_measurement="W",
            accuracy_decimals=1,
            icon="mdi:counter",
            device_class=DEVICE_CLASS_ENERGY,
            state_class=STATE_CLASS_MEASUREMENT,
        ),
        cv.Optional(CONF_DEVICE_BASE_HEATER): sensor.sensor_schema(
            icon="mdi:heating-coil",
        ),
        cv.Optional(CONF_DEVICE_BACKUP_HEATER): sensor.sensor_schema(
            icon="mdi:heating-coil",
        ),
        cv.Optional(CONF_DEVICE_BOOSTER_HEATER): sensor.sensor_schema(
            icon="mdi:heating-coil",
        ),
        cv.Optional(CONF_DEVICE_SERVICE): sensor.sensor_schema(
            icon="mdi:hospital-box-outline",
        ),
        cv.Optional(CONF_DEVICE_DEICE_MODE): sensor.sensor_schema(
            icon="mdi:ice-cream-off",
        ),
        cv.Optional(CONF_DEVICE_OPERATION_MODE_REAL): sensor.sensor_schema(
            icon="mdi:information-outline",
        ),
        cv.Optional(CONF_DEVICE_OPERATION_MODE_EXT): sensor.sensor_schema(
            icon="mdi:information-outline",
        ),
        cv.Optional(CONF_DEVICE_EVI_BYPASS_VALVE): sensor.sensor_schema(
            icon="mdi:valve",
        ),
        cv.Optional(CONF_DEVICE_DEICE_STATUS): sensor.sensor_schema(
            icon="mdi:ice-cream-off",
        ),
        cv.Optional(CONF_DEVICE_COMPRESSOR_STATUS): sensor.sensor_schema(
            icon="mdi:engine",
        ),
        cv.Optional(CONF_DEVICE_CURRENT_TEMP_ZONE2): sensor.sensor_schema(
            unit_of_measurement=UNIT_CELSIUS,
            accuracy_decimals=1,
            device_class=DEVICE_CLASS_TEMPERATURE,
            state_class=STATE_CLASS_MEASUREMENT,
        ),
        
        cv.Optional(CONF_DEVICE_INDOOR_EVA_IN_TEMPERATURE): sensor.sensor_schema(
            unit_of_measurement=UNIT_CELSIUS,
            accuracy_decimals=1,
            device_class=DEVICE_CLASS_TEMPERATURE,
            state_class=STATE_CLASS_MEASUREMENT,
        ),
        cv.Optional(CONF_DEVICE_INDOOR_EVA_OUT_TEMPERATURE): sensor.sensor_schema(
            unit_of_measurement=UNIT_CELSIUS,
            accuracy_decimals=1,
            device_class=DEVICE_CLASS_TEMPERATURE,
            state_class=STATE_CLASS_MEASUREMENT,
        ),
        cv.Optional(CONF_DEVICE_ERROR_CODE): error_code_sensor_schema(0x8235),
        cv.Optional(CONF_DEVICE_VENTILATOR): ventilator_sensor_schema(0x823D),
        cv.Optional(CONF_DEVICE_WATERPUMP_PWM): waterpump_pwm_sensor_schema(0x40C4),
        cv.Optional(CONF_DEVICE_TARGET_TEMPERATURE): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_WATER_OUTLET_TARGET): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_WATER_TARGET_TEMPERATURE): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_TARGET_TEMPERATURE_ZONE2): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV1011): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV1012): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV1021): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV1022): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV1031): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV1032): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV1041): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV1042): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV1051): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV1052): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV5011): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV5012): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV5013): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV5014): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV5015): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV5016): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV5017): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV5018): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV5019): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2012): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2021): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2022): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2031): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2032): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2051): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2052): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2061): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2062): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2071): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2072): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2041): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2081): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2091): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2092): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV2093): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3011): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3041): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3042): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3043): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3045): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3046): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3061): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV4061): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV5022): NUMBER_SCHEMA,

        cv.Optional(CONF_DEVICE_FSV3021): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3022): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3023): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3024): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3025): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3026): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3031): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3032): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3033): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3044): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3051): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3052): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3071): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3081): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3082): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV3083): NUMBER_SCHEMA,

        cv.Optional(CONF_DEVICE_FSV4011): NUMBER_SCHEMA,
 
        cv.Optional(CONF_DEVICE_FSV4013): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV4021): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV4022): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV4023): NUMBER_SCHEMA,

        cv.Optional(CONF_DEVICE_FSV4025): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV4031): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_FSV4032): NUMBER_SCHEMA,


        cv.Optional(CONF_DEVICE_TARGET_OFFSET): NUMBER_SCHEMA,
        cv.Optional(CONF_DEVICE_POWER): switch.switch_schema(Samsung_AC_Switch),
        cv.Optional(CONF_DEVICE_POWER_ZONE2): switch.switch_schema(Samsung_AC_Switch),
        cv.Optional(CONF_DEVICE_VACATION): switch.switch_schema(Samsung_AC_Switch),
        cv.Optional(CONF_DEVICE_AUTOMATIC_CLEANING): switch.switch_schema(
            Samsung_AC_Switch
        ),
        cv.Optional(CONF_DEVICE_WATER_HEATER_POWER): switch.switch_schema(
            Samsung_AC_Switch
        ),
        cv.Optional(CONF_DEVICE_MODE): SELECT_MODE_SCHEMA,
        cv.Optional(CONF_DEVICE_WATER_HEATER_MODE): SELECT_WATER_HEATER_MODE_SCHEMA,
        cv.Optional(CONF_DEVICE_WATER_HEATER_MODE): SELECT_WATER_HEATER_MODE_SCHEMA,
        cv.Optional(CONF_DEVICE_CLIMATE): CLIMATE_SCHEMA,
        cv.Optional(CONF_DEVICE_CUSTOM, default=[]): cv.ensure_list(
            CUSTOM_SENSOR_SCHEMA
        ),
        # keep CUSTOM_SENSOR_KEYS in sync with these
        cv.Optional(CONF_DEVICE_WATER_TEMPERATURE): temperature_sensor_schema(0x4237),
        cv.Optional(CONF_DEVICE_ROOM_HUMIDITY): humidity_sensor_schema(0x4038),
        cv.Optional(
            CONF_DEVICE_OUT_CONTROL_WATTMETER_ALL_UNIT_ACCUM
        ): sensor.sensor_schema(
            unit_of_measurement=UNIT_WATT,
            accuracy_decimals=1,
            device_class=DEVICE_CLASS_POWER,
            state_class=STATE_CLASS_MEASUREMENT,
            icon="mdi:flash",
        ),
        cv.Optional(
            CONF_DEVICE_OUT_CONTROL_WATTMETER_1W_1MIN_SUM
        ): sensor.sensor_schema(
            unit_of_measurement="kWh",
            accuracy_decimals=3,
            device_class=DEVICE_CLASS_ENERGY,
            state_class=STATE_CLASS_TOTAL_INCREASING,
            icon="mdi:counter",
        ).extend(
            {
                cv.Optional(
                    CONF_FILTERS, default=[{"multiply": 0.001}]
                ): sensor.validate_filters
            }
        ),
        cv.Optional(CONF_DEVICE_OUT_SENSOR_CT1): sensor.sensor_schema(
            unit_of_measurement=UNIT_AMPERE,
            accuracy_decimals=2,
            device_class=DEVICE_CLASS_CURRENT,
            state_class=STATE_CLASS_MEASUREMENT,
            icon="mdi:current-ac",
        ).extend(
            {
                cv.Optional(CONF_DEVICE_CUSTOM_MESSAGE, default=0x8217): cv.hex_int,
                cv.Optional(
                    CONF_FILTERS, default=[{"multiply": 0.1}]
                ): sensor.validate_filters,
            }
        ),
        cv.Optional(CONF_DEVICE_OUT_SENSOR_VOLTAGE): sensor.sensor_schema(
            unit_of_measurement=UNIT_VOLT,
            accuracy_decimals=1,
            device_class=DEVICE_CLASS_VOLTAGE,
            state_class=STATE_CLASS_MEASUREMENT,
            icon="mdi:flash",
        ).extend(
            {
                cv.Optional(CONF_DEVICE_CUSTOM_MESSAGE, default=0x24FC): cv.hex_int,
            }
        ),
    }
)

CUSTOM_SENSOR_KEYS = [
    CONF_DEVICE_WATER_TEMPERATURE,
    CONF_DEVICE_ROOM_HUMIDITY,
]

CONF_DEVICES = "devices"

CONF_DEBUG_MQTT_HOST = "debug_mqtt_host"
CONF_DEBUG_MQTT_PORT = "debug_mqtt_port"
CONF_DEBUG_MQTT_USERNAME = "debug_mqtt_username"
CONF_DEBUG_MQTT_PASSWORD = "debug_mqtt_password"

CONF_DEBUG_LOG_MESSAGES = "debug_log_messages"
CONF_DEBUG_LOG_MESSAGES_RAW = "debug_log_messages_raw"

CONF_NON_NASA_KEEPALIVE = "non_nasa_keepalive"

CONF_DEBUG_LOG_UNDEFINED_MESSAGES = "debug_log_undefined_messages"


CONFIG_SCHEMA = (
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(Samsung_AC),
            # cv.Optional(CONF_PAUSE, default=False): cv.boolean,
            cv.Optional(CONF_DEBUG_MQTT_HOST, default=""): cv.string,
            cv.Optional(CONF_DEBUG_MQTT_PORT, default=1883): cv.int_,
            cv.Optional(CONF_DEBUG_MQTT_USERNAME, default=""): cv.string,
            cv.Optional(CONF_DEBUG_MQTT_PASSWORD, default=""): cv.string,
            cv.Optional(CONF_DEBUG_LOG_MESSAGES, default=False): cv.boolean,
            cv.Optional(CONF_DEBUG_LOG_MESSAGES_RAW, default=False): cv.boolean,
            cv.Optional(CONF_NON_NASA_KEEPALIVE, default=False): cv.boolean,
            cv.Optional(CONF_DEBUG_LOG_UNDEFINED_MESSAGES, default=False): cv.boolean,
            cv.Optional(CONF_CAPABILITIES): CAPABILITIES_SCHEMA,
            cv.Required(CONF_DEVICES): cv.ensure_list(DEVICE_SCHEMA),
        }
    )
    .extend(uart.UART_DEVICE_SCHEMA)
    .extend(cv.polling_component_schema("30s"))
)


async def to_code(config):
    # For Debug_MQTT
    if CORE.is_esp8266 or CORE.is_libretiny:
        cg.add_library("heman/AsyncMqttClient-esphome", "2.0.0")

    var = cg.new_Pvariable(config[CONF_ID])
    for device_index, device in enumerate(config[CONF_DEVICES]):
        var_dev = cg.new_Pvariable(
            device[CONF_DEVICE_ID], device[CONF_DEVICE_ADDRESS], var
        )

        # setup capabilities
        capabilities = device.get(CONF_CAPABILITIES, config.get(CONF_CAPABILITIES, {}))

        if CONF_CAPABILITIES_VERTICAL_SWING in capabilities:
            cg.add(
                var_dev.set_supports_vertical_swing(
                    capabilities[CONF_CAPABILITIES_VERTICAL_SWING]
                )
            )

        if CONF_CAPABILITIES_HORIZONTAL_SWING in capabilities:
            cg.add(
                var_dev.set_supports_horizontal_swing(
                    capabilities[CONF_CAPABILITIES_HORIZONTAL_SWING]
                )
            )

        none_added = False
        presets = capabilities.get(CONF_PRESETS, {})

        for preset, preset_info in PRESETS.items():
            preset_conf = presets.get(preset, None)

            if isinstance(preset_conf, bool) and preset_conf:
                if not none_added:
                    none_added = True
                    cg.add(var_dev.add_alt_mode("None", 0))

                cg.add(
                    var_dev.add_alt_mode(
                        preset_info["displayName"], preset_info["value"]
                    )
                )
            elif isinstance(preset_conf, dict) and preset_conf.get(
                CONF_PRESET_ENABLED, False
            ):
                if not none_added:
                    none_added = True
                    cg.add(var_dev.add_alt_mode("None", 0))

                cg.add(
                    var_dev.add_alt_mode(
                        preset_conf.get(
                            CONF_PRESET_NAME, preset_info["displayName"]
                        ),  # Kullanıcı tarafından sağlanan adı kullan
                        preset_conf.get(
                            CONF_PRESET_VALUE, preset_info["value"]
                        ),  # Kullanıcı tarafından sağlanan değeri kullan
                    )
                )

        #        if CONF_CAPABILITIES in device and CONF_ALT_MODES in device[CONF_CAPABILITIES]:
        #            cg.add(var_dev.add_alt_mode("None", 0))
        #            for alt in device[CONF_CAPABILITIES][CONF_ALT_MODES]:
        #                cg.add(var_dev.add_alt_mode(alt[CONF_ALT_MODE_NAME], alt[CONF_ALT_MODE_VALUE]))
        #        elif CONF_CAPABILITIES in config and CONF_ALT_MODES in config[CONF_CAPABILITIES]:
        #            cg.add(var_dev.add_alt_mode("None", 0))
        #            for alt in config[CONF_CAPABILITIES][CONF_ALT_MODES]:
        #                cg.add(var_dev.add_alt_mode(alt[CONF_ALT_MODE_NAME], alt[CONF_ALT_MODE_VALUE]))

        # Mapping of config keys to their corresponding methods and types
        device_actions = {
            CONF_DEVICE_POWER: (switch.new_switch, var_dev.set_power_switch),
            CONF_DEVICE_POWER_ZONE2: (switch.new_switch, var_dev.set_power_zone2_switch),
            CONF_DEVICE_VACATION: (switch.new_switch, var_dev.set_vacation_switch),
            CONF_DEVICE_AUTOMATIC_CLEANING: (
                switch.new_switch,
                var_dev.set_automatic_cleaning_switch,
            ),
            CONF_DEVICE_WATER_HEATER_POWER: (
                switch.new_switch,
                var_dev.set_water_heater_power_switch,
            ),
            CONF_DEVICE_ROOM_TEMPERATURE: (
                sensor.new_sensor,
                var_dev.set_room_temperature_sensor,
            ),
            CONF_DEVICE_CURRENT_TEMP_ZONE1: (
                sensor.new_sensor,
                var_dev.set_current_temp_zone1_sensor,
            ),
            CONF_DEVICE_WATER_TEMPERATURE_OUT: (
                sensor.new_sensor,
                var_dev.set_water_temperature_out_sensor,
            ),
            CONF_DEVICE_DISCHARGE_TEMP: (
                sensor.new_sensor,
                var_dev.set_discharge_temp_sensor,
            ),
            CONF_DEVICE_WATER_PRESSURE: (
                sensor.new_sensor,
                var_dev.set_water_pressure_sensor,
            ),
            CONF_DEVICE_TEMP_MIXING_VALVE: (
                sensor.new_sensor,
                var_dev.set_temp_mixing_valve_sensor,
            ),
            CONF_DEVICE_3WAY_VALVE: (
                sensor.new_sensor,
                var_dev.set_3way_valve_sensor,
            ),
            CONF_DEVICE_WATERFLOW: (
                sensor.new_sensor,
                var_dev.set_waterflow_sensor,
            ),
            CONF_DEVICE_COOLANT: (
                sensor.new_sensor,
                var_dev.set_coolant_sensor,
            ),
            CONF_DEVICE_COMPRESSOR_FREQUENCY: (
                sensor.new_sensor,
                var_dev.set_compressor_frequency_sensor,
            ),
            CONF_DEVICE_COMPRESSOR_FREQUENCY_ORDER: (
                sensor.new_sensor,
                var_dev.set_compressor_frequency_order_sensor,
            ),
            CONF_DEVICE_COMPRESSOR_FREQUENCY_TARGET: (
                sensor.new_sensor,
                var_dev.set_compressor_frequency_target_sensor,
            ),
            CONF_DEVICE_ENERGY_PRODUCED_LIFETIME: (
                sensor.new_sensor,
                var_dev.set_energy_produced_lifetime_sensor,
            ),
            CONF_DEVICE_ENERGY_PRODUCED_NOW: (
                sensor.new_sensor,
                var_dev.set_energy_produced_now_sensor,
            ),
            CONF_DEVICE_BASE_HEATER: (
                sensor.new_sensor,
                var_dev.set_base_heater_sensor,
            ),
            CONF_DEVICE_BACKUP_HEATER: (
                sensor.new_sensor,
                var_dev.set_backup_heater_sensor,
            ),
            CONF_DEVICE_BOOSTER_HEATER: (
                sensor.new_sensor,
                var_dev.set_booster_heater_sensor,
            ),
            CONF_DEVICE_SERVICE: (
                sensor.new_sensor,
                var_dev.set_service_sensor,
            ),
            CONF_DEVICE_DEICE_STATUS: (
                sensor.new_sensor,
                var_dev.set_deice_status_sensor,
            ),
            CONF_DEVICE_COMPRESSOR_STATUS: (
                sensor.new_sensor,
                var_dev.set_compressor_status_sensor,
            ),
            CONF_DEVICE_DEICE_MODE: (
                sensor.new_sensor,
                var_dev.set_deice_mode_sensor,
            ),
            CONF_DEVICE_OPERATION_MODE_REAL: (
                sensor.new_sensor,
                var_dev.set_operation_mode_real_sensor,
            ),
            CONF_DEVICE_OPERATION_MODE_EXT: (
                sensor.new_sensor,
                var_dev.set_operation_mode_ext_sensor,
            ),
            CONF_DEVICE_EVI_BYPASS_VALVE: (
                sensor.new_sensor,
                var_dev.set_evi_bypass_valve_sensor,
            ),
            CONF_DEVICE_CURRENT_TEMP_ZONE2: (
                sensor.new_sensor,
                var_dev.set_current_temp_zone2_sensor,
            ),

            CONF_DEVICE_OUTDOOR_TEMPERATURE: (
                sensor.new_sensor,
                var_dev.set_outdoor_temperature_sensor,
            ),
            CONF_DEVICE_INDOOR_EVA_IN_TEMPERATURE: (
                sensor.new_sensor,
                var_dev.set_indoor_eva_in_temperature_sensor,
            ),
            CONF_DEVICE_INDOOR_EVA_OUT_TEMPERATURE: (
                sensor.new_sensor,
                var_dev.set_indoor_eva_out_temperature_sensor,
            ),
            CONF_DEVICE_ERROR_CODE: (sensor.new_sensor, var_dev.set_error_code_sensor),
            CONF_DEVICE_VENTILATOR: (sensor.new_sensor, var_dev.set_ventilator_sensor),
            CONF_DEVICE_WATERPUMP_PWM: (sensor.new_sensor, var_dev.set_waterpump_pwm_sensor),
            CONF_DEVICE_OUT_CONTROL_WATTMETER_ALL_UNIT_ACCUM: (
                sensor.new_sensor,
                var_dev.set_outdoor_instantaneous_power_sensor,
            ),
            CONF_DEVICE_OUT_CONTROL_WATTMETER_1W_1MIN_SUM: (
                sensor.new_sensor,
                var_dev.set_outdoor_cumulative_energy_sensor,
            ),
            CONF_DEVICE_OUT_SENSOR_CT1: (
                sensor.new_sensor,
                var_dev.set_outdoor_current_sensor,
            ),
            CONF_DEVICE_OUT_SENSOR_VOLTAGE: (
                sensor.new_sensor,
                var_dev.set_outdoor_voltage_sensor,
            ),
        }

        # Iterate over the actions
        for key, (action, method) in device_actions.items():
            if key in device:
                conf = device[key]
                sens = await action(conf)
                cg.add(method(sens))

        if CONF_DEVICE_ROOM_TEMPERATURE_OFFSET in device:
            cg.add(
                var_dev.set_room_temperature_offset(
                    device[CONF_DEVICE_ROOM_TEMPERATURE_OFFSET]
                )
            )

        if CONF_DEVICE_WATER_TARGET_TEMPERATURE in device:
            conf = device[CONF_DEVICE_WATER_TARGET_TEMPERATURE]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=30.0, max_value=60.0, step=0.1
            )
            cg.add(var_dev.set_target_water_temperature_number(num))

        if CONF_DEVICE_TARGET_TEMPERATURE in device:
            conf = device[CONF_DEVICE_TARGET_TEMPERATURE]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=23.0, max_value=40.0, step=0.1
            )
            cg.add(var_dev.set_target_temperature_number(num))
        if CONF_DEVICE_TARGET_TEMPERATURE_ZONE2 in device:
            conf = device[CONF_DEVICE_TARGET_TEMPERATURE_ZONE2]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=23.0, max_value=43.0, step=0.1
            )
            cg.add(var_dev.set_target_temperature_zone2_number(num))
        
        if CONF_DEVICE_FSV1011 in device:
            conf = device[CONF_DEVICE_FSV1011]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=18.0, max_value=25.0, step=1
            )
            cg.add(var_dev.set_fsv1011_number(num))

        if CONF_DEVICE_FSV1012 in device:
            conf = device[CONF_DEVICE_FSV1012]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=5.0, max_value=18.0, step=1
            )
            cg.add(var_dev.set_fsv1012_number(num))

        if CONF_DEVICE_FSV1021 in device:
            conf = device[CONF_DEVICE_FSV1021]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=28.0, max_value=30.0, step=1
            )
            cg.add(var_dev.set_fsv1021_number(num))

        if CONF_DEVICE_FSV1022 in device:
            conf = device[CONF_DEVICE_FSV1022]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=18.0, max_value=28.0, step=1
            )
            cg.add(var_dev.set_fsv1022_number(num))

        if CONF_DEVICE_FSV1031 in device:
            conf = device[CONF_DEVICE_FSV1031]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=37.0, max_value=70.0, step=1
            )
            cg.add(var_dev.set_fsv1031_number(num))

        if CONF_DEVICE_FSV1032 in device:
            conf = device[CONF_DEVICE_FSV1032]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=15.0, max_value=37.0, step=1
            )
            cg.add(var_dev.set_fsv1032_number(num))

        if CONF_DEVICE_FSV1041 in device:
            conf = device[CONF_DEVICE_FSV1041]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=18.0, max_value=30.0, step=1
            )
            cg.add(var_dev.set_fsv1041_number(num))

        if CONF_DEVICE_FSV1042 in device:
            conf = device[CONF_DEVICE_FSV1042]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=16.0, max_value=18.0, step=1
            )
            cg.add(var_dev.set_fsv1042_number(num))

        if CONF_DEVICE_FSV1051 in device:
            conf = device[CONF_DEVICE_FSV1051]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=50.0, max_value=70.0, step=1
            )
            cg.add(var_dev.set_fsv1051_number(num))

        if CONF_DEVICE_FSV1052 in device:
            conf = device[CONF_DEVICE_FSV1052]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=30.0, max_value=40.0, step=1
            )
            cg.add(var_dev.set_fsv1052_number(num))
        if CONF_DEVICE_FSV5011 in device:
            conf = device[CONF_DEVICE_FSV5011]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=5.0, max_value=25.0, step=1
            )
            cg.add(var_dev.set_fsv5011_number(num))
        if CONF_DEVICE_FSV5012 in device:
            conf = device[CONF_DEVICE_FSV5012]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=18.0, max_value=30.0, step=1
            )
            cg.add(var_dev.set_fsv5012_number(num))
        if CONF_DEVICE_FSV5013 in device:
            conf = device[CONF_DEVICE_FSV5013]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=15.0, max_value=55.0, step=1
            )
            cg.add(var_dev.set_fsv5013_number(num))
        if CONF_DEVICE_FSV5014 in device:
            conf = device[CONF_DEVICE_FSV5014]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=16.0, max_value=30.0, step=1
            )
            cg.add(var_dev.set_fsv5014_number(num))
        if CONF_DEVICE_FSV5015 in device:
            conf = device[CONF_DEVICE_FSV5015]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=5.0, max_value=25.0, step=1
            )
            cg.add(var_dev.set_fsv5015_number(num))
        if CONF_DEVICE_FSV5016 in device:
            conf = device[CONF_DEVICE_FSV5016]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=5.0, max_value=25.0, step=1
            )
            cg.add(var_dev.set_fsv5016_number(num))
        if CONF_DEVICE_FSV5017 in device:
            conf = device[CONF_DEVICE_FSV5017]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=15.0, max_value=55.0, step=1
            )
            cg.add(var_dev.set_fsv5017_number(num))
        if CONF_DEVICE_FSV5018 in device:
            conf = device[CONF_DEVICE_FSV5018]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=15.0, max_value=55.0, step=1
            )
            cg.add(var_dev.set_fsv5018_number(num))
        if CONF_DEVICE_FSV5019 in device:
            conf = device[CONF_DEVICE_FSV5019]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=30.0, max_value=70.0, step=1
            )
            cg.add(var_dev.set_fsv5019_number(num))
        if CONF_DEVICE_FSV2012 in device:
            conf = device[CONF_DEVICE_FSV2012]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=10.0, max_value=20.0, step=1
            )
            cg.add(var_dev.set_fsv2012_number(num))
        if CONF_DEVICE_FSV2021 in device:
            conf = device[CONF_DEVICE_FSV2021]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=17.0, max_value=65.0, step=1
            )
            cg.add(var_dev.set_fsv2021_number(num))
        if CONF_DEVICE_FSV2022 in device:
            conf = device[CONF_DEVICE_FSV2022]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=17.0, max_value=65.0, step=1
            )
            cg.add(var_dev.set_fsv2022_number(num))
        if CONF_DEVICE_FSV2031 in device:
            conf = device[CONF_DEVICE_FSV2031]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=17.0, max_value=65.0, step=1
            )
            cg.add(var_dev.set_fsv2031_number(num))
        if CONF_DEVICE_FSV2032 in device:
            conf = device[CONF_DEVICE_FSV2032]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=17.0, max_value=65.0, step=1
            )
            cg.add(var_dev.set_fsv2032_number(num))
        if CONF_DEVICE_FSV2051 in device:
            conf = device[CONF_DEVICE_FSV2051]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=25.0, max_value=35.0, step=1
            )
            cg.add(var_dev.set_fsv2051_number(num))
        if CONF_DEVICE_FSV2052 in device:
            conf = device[CONF_DEVICE_FSV2052]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=35.0, max_value=45.0, step=1
            )
            cg.add(var_dev.set_fsv2052_number(num))
        if CONF_DEVICE_FSV2061 in device:
            conf = device[CONF_DEVICE_FSV2061]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=5.0, max_value=25.0, step=1
            )

            cg.add(var_dev.set_fsv2061_number(num))
        if CONF_DEVICE_FSV2062 in device:
            conf = device[CONF_DEVICE_FSV2062]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=5.0, max_value=25.0, step=1
            )
            cg.add(var_dev.set_fsv2062_number(num))
        if CONF_DEVICE_FSV2071 in device:
            conf = device[CONF_DEVICE_FSV2071]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=5.0, max_value=25.0, step=1
            )
            cg.add(var_dev.set_fsv2071_number(num))
        if CONF_DEVICE_FSV2072 in device:
            conf = device[CONF_DEVICE_FSV2072]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=5.0, max_value=25.0, step=1
            )
            cg.add(var_dev.set_fsv2072_number(num))
        if CONF_DEVICE_FSV2041 in device:
            conf = device[CONF_DEVICE_FSV2041]
            num = await number.new_number(
                conf, min_value=1, max_value=2, step=1
            )
            cg.add(var_dev.set_fsv2041_number(num))



        if CONF_DEVICE_FSV3021 in device:
            conf = device[CONF_DEVICE_FSV3021]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=45, max_value=63, step=1
            )
            cg.add(var_dev.set_fsv3021_number(num))
        if CONF_DEVICE_FSV3022 in device:
            conf = device[CONF_DEVICE_FSV3022]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=0, max_value=10, step=1
            )
            cg.add(var_dev.set_fsv3022_number(num))
        if CONF_DEVICE_FSV3023 in device:
            conf = device[CONF_DEVICE_FSV3023]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=5, max_value=30, step=1
            )
            cg.add(var_dev.set_fsv3023_number(num))
        if CONF_DEVICE_FSV3024 in device:
            conf = device[CONF_DEVICE_FSV3024]
            conf[CONF_DEVICE_CLASS] = "min"
            num = await number.new_number(
                conf, min_value=1, max_value=20, step=1
            )
            cg.add(var_dev.set_fsv3024_number(num))
        if CONF_DEVICE_FSV3025 in device:
            conf = device[CONF_DEVICE_FSV3025]
            conf[CONF_DEVICE_CLASS] = "min"
            num = await number.new_number(
                conf, min_value=5, max_value=95, step=1
            )
            cg.add(var_dev.set_fsv3025_number(num))
        if CONF_DEVICE_FSV3026 in device:
            conf = device[CONF_DEVICE_FSV3026]
            conf[CONF_DEVICE_CLASS] = "h"
            num = await number.new_number(
                conf, min_value=0.5, max_value=10, step=0.5
            )
            cg.add(var_dev.set_fsv3026_number(num))
        if CONF_DEVICE_FSV3031 in device:
            conf = device[CONF_DEVICE_FSV3031]
            num = await number.new_number(
                conf, min_value=0, max_value=1, step=1
            )
            cg.add(var_dev.set_fsv3031_number(num))
        if CONF_DEVICE_FSV3032 in device:
            conf = device[CONF_DEVICE_FSV3032]
            conf[CONF_DEVICE_CLASS] = "min"
            num = await number.new_number(
                conf, min_value=20, max_value=95, step=1
            )
            cg.add(var_dev.set_fsv3032_number(num))
        if CONF_DEVICE_FSV3033 in device:
            conf = device[CONF_DEVICE_FSV3033]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=0, max_value=4, step=1
            )
            cg.add(var_dev.set_fsv3033_number(num))
        if CONF_DEVICE_FSV3044 in device:
            conf = device[CONF_DEVICE_FSV3044]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=40, max_value=70, step=1
            )
            cg.add(var_dev.set_fsv3044_number(num))
        if CONF_DEVICE_FSV3051 in device:
            conf = device[CONF_DEVICE_FSV3051]
            num = await number.new_number(
                conf, min_value=0, max_value=1, step=1
            )
            cg.add(var_dev.set_fsv3051_number(num))
        if CONF_DEVICE_FSV3052 in device:
            conf[CONF_DEVICE_CLASS] = "min"
            num = await number.new_number(
                conf, min_value=3, max_value=30, step=1
            )
            cg.add(var_dev.set_fsv3052_number(num))
        if CONF_DEVICE_FSV3071 in device:
            conf = device[CONF_DEVICE_FSV3071]
            num = await number.new_number(
                conf, min_value=0, max_value=1, step=1
            )
            cg.add(var_dev.set_fsv3071_number(num))
        if CONF_DEVICE_FSV3081 in device:
            conf = device[CONF_DEVICE_FSV3081]
            num = await number.new_number(
                conf, min_value=1, max_value=6, step=1
            )
            cg.add(var_dev.set_fsv3081_number(num))
        if CONF_DEVICE_FSV3082 in device:
            conf = device[CONF_DEVICE_FSV3082]
            num = await number.new_number(
                conf, min_value=0, max_value=6, step=1
            )
            cg.add(var_dev.set_fsv3082_number(num))
        if CONF_DEVICE_FSV3083 in device:
            conf = device[CONF_DEVICE_FSV3083]
            num = await number.new_number(
                conf, min_value=1, max_value=6, step=1
            )
            cg.add(var_dev.set_fsv3083_number(num))

        if CONF_DEVICE_FSV2081 in device: 
            conf = device[CONF_DEVICE_FSV2081]
            num = await number.new_number(
                conf, min_value=1, max_value=2, step=1
            )
            cg.add(var_dev.set_fsv2081_number(num))

        if CONF_DEVICE_FSV2091 in device: 
            conf = device[CONF_DEVICE_FSV2091]
            num = await number.new_number(
                conf, min_value=0, max_value=4, step=1
            )
            cg.add(var_dev.set_fsv2091_number(num))

        if CONF_DEVICE_FSV2092 in device: 
            conf = device[CONF_DEVICE_FSV2092]
            num = await number.new_number(
                conf, min_value=0, max_value=4, step=1
            )
            cg.add(var_dev.set_fsv2092_number(num))

        if CONF_DEVICE_FSV2093 in device: 
            conf = device[CONF_DEVICE_FSV2093]
            num = await number.new_number(
                conf, min_value=1, max_value=4, step=1
            )
            cg.add(var_dev.set_fsv2093_number(num))

        if CONF_DEVICE_FSV3011 in device: 
            conf = device[CONF_DEVICE_FSV3011]
            num = await number.new_number(
                conf, min_value=0, max_value=2, step=1
            )
            cg.add(var_dev.set_fsv3011_number(num))

        if CONF_DEVICE_FSV3041 in device: 
            conf = device[CONF_DEVICE_FSV3041]
            num = await number.new_number(
                conf, min_value=0, max_value=1, step=1
            )
            cg.add(var_dev.set_fsv3041_number(num))

        if CONF_DEVICE_FSV3042 in device: 
            conf = device[CONF_DEVICE_FSV3042]
            num = await number.new_number(
                conf, min_value=0, max_value=7, step=1
            )
            cg.add(var_dev.set_fsv3042_number(num))
        if CONF_DEVICE_FSV3043 in device: 
            conf = device[CONF_DEVICE_FSV3043]
            num = await number.new_number(
                conf, min_value=0, max_value=23, step=1
            )
            cg.add(var_dev.set_fsv3043_number(num))

        if CONF_DEVICE_FSV3045 in device: 
            conf = device[CONF_DEVICE_FSV3045]
            conf[CONF_UNIT_OF_MEASUREMENT] = "min"
            num = await number.new_number(
                conf, min_value=5, max_value=60, step=1
            )
            cg.add(var_dev.set_fsv3045_number(num))

        if CONF_DEVICE_FSV3046 in device: 
            conf = device[CONF_DEVICE_FSV3046]
            conf[CONF_UNIT_OF_MEASUREMENT] = "min"
            num = await number.new_number(
                conf, min_value=10, max_value=240, step=10
            )
            cg.add(var_dev.set_fsv3046_number(num))

        if CONF_DEVICE_FSV3061 in device: 
            conf = device[CONF_DEVICE_FSV3061]
            num = await number.new_number(
                conf, min_value=0, max_value=2, step=1
            )
            cg.add(var_dev.set_fsv3061_number(num))

        if CONF_DEVICE_FSV4061 in device: 
            conf = device[CONF_DEVICE_FSV4061]
            num = await number.new_number(
                conf, min_value=0, max_value=1, step=1
            )
            cg.add(var_dev.set_fsv4061_number(num))

        if CONF_DEVICE_FSV5022 in device: 
            conf = device[CONF_DEVICE_FSV5022]
            num = await number.new_number(
                conf, min_value=0, max_value=1, step=1
            )
            cg.add(var_dev.set_fsv5022_number(num))
        
        if CONF_DEVICE_FSV4011 in device:
            conf = device[CONF_DEVICE_FSV4011]
            num = await number.new_number(
                conf, min_value=0, max_value=1, step=1
            )
            cg.add(var_dev.set_fsv4011_number(num))

        if CONF_DEVICE_FSV4013 in device:
            conf = device[CONF_DEVICE_FSV4013]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=14, max_value=45, step=1
            )
            cg.add(var_dev.set_fsv4013_number(num))

        if CONF_DEVICE_FSV4021 in device:
            conf = device[CONF_DEVICE_FSV4021]
            num = await number.new_number(
                conf, min_value=0, max_value=2, step=1
            )
            cg.add(var_dev.set_fsv4021_number(num))

        if CONF_DEVICE_FSV4022 in device:
            conf = device[CONF_DEVICE_FSV4022]
            num = await number.new_number(
                conf, min_value=0, max_value=2, step=1
            )
            cg.add(var_dev.set_fsv4022_number(num))

        if CONF_DEVICE_FSV4023 in device:
            conf = device[CONF_DEVICE_FSV4023]
            num = await number.new_number(
                conf, min_value=0, max_value=1, step=1
            )
            cg.add(var_dev.set_fsv4023_number(num))

        if CONF_DEVICE_FSV4025 in device:
            conf = device[CONF_DEVICE_FSV4025]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=10, max_value=55, step=1
            )
            cg.add(var_dev.set_fsv4025_number(num))

        if CONF_DEVICE_FSV4031 in device:
            conf = device[CONF_DEVICE_FSV4031]
            num = await number.new_number(
                conf, min_value=0, max_value=1, step=1
            )
            cg.add(var_dev.set_fsv4031_number(num))

        if CONF_DEVICE_FSV4032 in device:
            conf = device[CONF_DEVICE_FSV4032]
            num = await number.new_number(
                conf, min_value=0, max_value=1, step=1
            )
            cg.add(var_dev.set_fsv4032_number(num))

        

        





        if CONF_DEVICE_TARGET_OFFSET in device:
            conf = device[CONF_DEVICE_TARGET_OFFSET]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=-5.0, max_value=5.0, step=0.1
            )
            cg.add(var_dev.set_target_offset_number(num))

        if CONF_DEVICE_WATER_OUTLET_TARGET in device:
            conf = device[CONF_DEVICE_WATER_OUTLET_TARGET]
            conf[CONF_UNIT_OF_MEASUREMENT] = UNIT_CELSIUS
            conf[CONF_DEVICE_CLASS] = DEVICE_CLASS_TEMPERATURE
            num = await number.new_number(
                conf, min_value=23.0, max_value=43.0, step=0.1
            )
            cg.add(var_dev.set_water_outlet_target_number(num))

        if CONF_DEVICE_MODE in device:
            conf = device[CONF_DEVICE_MODE]
            values = ["Auto", "Cool", "Heat"]
            sel = await select.new_select(conf, options=values)
            cg.add(var_dev.set_mode_select(sel))

        if CONF_DEVICE_WATER_HEATER_MODE in device:
            conf = device[CONF_DEVICE_WATER_HEATER_MODE]
            values = ["Eco", "Standard", "Force"]
            sel = await select.new_select(conf, options=values)
            cg.add(var_dev.set_water_heater_mode_select(sel))

        if CONF_DEVICE_CLIMATE in device:
            conf = device[CONF_DEVICE_CLIMATE]
            var_cli = cg.new_Pvariable(conf[CONF_ID])
            await climate.register_climate(var_cli, conf)
            cg.add(var_dev.set_climate(var_cli))

        if CONF_DEVICE_CUSTOM in device:
            for cust_sens in device[CONF_DEVICE_CUSTOM]:
                sens = await sensor.new_sensor(cust_sens)
                cg.add(
                    var_dev.add_custom_sensor(
                        cust_sens[CONF_DEVICE_CUSTOM_MESSAGE], sens
                    )
                )

        for key in CUSTOM_SENSOR_KEYS:
            if key in device:
                conf = device[key]
                # combine raw filters with any user-defined filters
                conf_copy = conf.copy()
                conf_copy[CONF_FILTERS] = (
                    conf[CONF_DEVICE_CUSTOM_RAW_FILTERS]
                    if CONF_DEVICE_CUSTOM_RAW_FILTERS in conf
                    else []
                ) + (conf[CONF_FILTERS] if CONF_FILTERS in conf else [])
                sens = await sensor.new_sensor(conf_copy)
                cg.add(
                    var_dev.add_custom_sensor(conf[CONF_DEVICE_CUSTOM_MESSAGE], sens)
                )

        cg.add(var.register_device(var_dev))

    cg.add(
        var.set_debug_mqtt(
            config[CONF_DEBUG_MQTT_HOST],
            config[CONF_DEBUG_MQTT_PORT],
            config[CONF_DEBUG_MQTT_USERNAME],
            config[CONF_DEBUG_MQTT_PASSWORD],
        )
    )

    if CONF_DEBUG_LOG_MESSAGES in config:
        cg.add(var.set_debug_log_messages(config[CONF_DEBUG_LOG_MESSAGES]))

    if CONF_DEBUG_LOG_MESSAGES_RAW in config:
        cg.add(var.set_debug_log_messages_raw(config[CONF_DEBUG_LOG_MESSAGES_RAW]))

    if CONF_NON_NASA_KEEPALIVE in config:
        cg.add(var.set_non_nasa_keepalive(config[CONF_NON_NASA_KEEPALIVE]))

    if CONF_DEBUG_LOG_UNDEFINED_MESSAGES in config:
        cg.add(
            var.set_debug_log_undefined_messages(
                config[CONF_DEBUG_LOG_UNDEFINED_MESSAGES]
            )
        )

    # Mapping of config keys to their corresponding methods
    config_actions = {
        CONF_DEBUG_LOG_MESSAGES: var.set_debug_log_messages,
        CONF_DEBUG_LOG_MESSAGES_RAW: var.set_debug_log_messages_raw,
        CONF_NON_NASA_KEEPALIVE: var.set_non_nasa_keepalive,
        CONF_DEBUG_LOG_UNDEFINED_MESSAGES: var.set_debug_log_undefined_messages,
    }

    # Iterate over the actions
    for key, method in config_actions.items():
        if key in config:
            cg.add(method(config[key]))

    await cg.register_component(var, config)
    await uart.register_uart_device(var, config)
