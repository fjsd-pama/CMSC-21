def risk_level(bmi, age):
    if (bmi < 22.0 and age < 45):
	return "Low"
    elif (bmi >= 22.0 and age < 45)or (bmi < 22.0 and age >= 45):
	return "Medium"
    else:
	return "High"



# number 1
# template
# def camera_switch_on(lux, temp):
# """(num, num) -> bool
#
# Determine whether to turn on the camera given the light level and
# the temperature
# """
# return 0


light_level = 0.01
freezing_pt = 0

# template
# def camera_switch_on(lux, temp):
# """(num, num) -> bool
#
# Determine whether to turn on the camera given the light level and
# the temperature
# """
# return... lux temp light_level freezing_pt

def camera_switch_on(lux, temp):
    """(num, num) -> bool

    Determines whether to turn on the camera given the light
    level and the temperature
    """
    return (lux < light_level) != (temp > freezing_pt)

#example
camera_switch_on(0, 0)#True
camera_switch_on(-1, 0) #True
camera_switch_on(0.01, 0) #True
camera_switch_on(0.2, 0) #False
camera_switch_on(-1, 1) #False
camera_switch_on(0.2, -2) #False
camera_switch_on(0.2, 2) #True

#define BMI_CONSTANT 22.0
#define AGE_CONSTANT 45

int risk_level(int BMI, int age){
	if ((BMI >= BMI_CONSTANT) && (age >= AGE_CONSTANT)){
		return 3;
	}else if (((BMI >= BMI_CONSTANT) && (age < AGE_CONSTANT)) || ((BMI < BMI_CONSTANT) && (age >= AGE_CONSTANT))){
		return 2;
    }else{
		return 1;
	}
}


