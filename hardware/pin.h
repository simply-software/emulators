#pragma once

#include <cstdint>
#include <type_traits>

namespace hw {

    // Defines the type of signal the pin can send/receive
    enum class PinType : uint8_t {        
        DIGITAL,  // This pin has value 0 or 1.
        ANALOG    // This pin does not have discrete values.  Usually used for voltages.
    }; // PinType enum
    
    
    // A pin is the only way a chip can input and/or output signals.
    template <PinType DATA_TYPE>
    class Pin {
    private:
        template <PinType PIN_TYPE = PinType::DIGITAL>
        struct DataType {
            using type = bool;
        };
        
        template <>
        struct DataType<PinType::ANALOG> {
            using type = double;
        };
        
    public:
        using value_type = DataType<DATA_TYPE>::type;
        using signal_type = DATA_TYPE;
                
    public:        
        value_type get_value() const {
            return m_value;
        }
        
        template <typename NEW_VALUE_TYPE>
        typename std::enable_if<std::is_same<NEW_VALUE_TYPE, value_type>::value, void>::type 
        set_value(NEW_VALUE_TYPE new_value)
            m_value = new_value;
        }
    
    private:
        value_type m_value = value_type{}; // Value currently asserted on this pin
    }; // Pin class
        
} // namespace hw