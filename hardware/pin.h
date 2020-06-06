#pragma once

#include <cstdint>
#include <type_traits>

namespace hw {

    // Defines the type of signal the pin can send/receive
    enum class PinType : uint8_t {        
        DIGITAL,  // This pin has value 0 or 1.
        ANALOG    // This pin does not have discrete values.  Usually used for voltages.
    }; // PinType enum

    namespace {
        // @brief DIGITAL pins carry either logical "0" (false) or "1" (true).
        template <PinType PIN_TYPE = PinType::DIGITAL>
        struct DataType {
            using type = bool;
        };

        // @brief ANALOG pins carry non-discrete values
        template <>
        struct DataType<PinType::ANALOG> {
            using type = double;
        };
    }
    
    // @brief A pin is the only way a chip can input and/or output signals.
    template <PinType DATA_TYPE>
    class Pin final {
    public:
        using value_type = typename DataType<DATA_TYPE>::type;
                
    public:   
        // @brief Default constructor
        //
        // This constructor asserts "zero" on the Pin (false or 0.0)
        //
        Pin() : m_value() 
        {}
        
        // @brief obtains the value that is currently asserted on the pin.
        // @return the value currently asserted on the pin
        //
        value_type get_value() const noexcept {
            return m_value;
        }
        
        // @brief Asserts a new value on the pin.
        // 
        // The templating mechanism applied here ensures that the parameter type given
        // matches the type that the Pin holds, for type safety reasons.  This way, you
        // can assert only "true" or "false" on a DIGITAL pin or a floating point value
        // on an analog Pin.
        //
        // @param new_value - the new value to assert on the Pin.
        //
        template <typename NEW_VALUE_TYPE>
        typename std::enable_if<std::is_same<NEW_VALUE_TYPE, value_type>::value, void>::type 
        set_value(NEW_VALUE_TYPE new_value) noexcept {
            m_value = new_value;
        }
    
    private:
        value_type m_value; // Value currently asserted on this pin
    }; // Pin class
        
} // namespace hw