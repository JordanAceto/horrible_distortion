EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 8
Title "Bit Crusher Pedal"
Date "2020-08-16"
Rev "1"
Comp ""
Comment1 "creativecommons.org/licenses/by/4.0/"
Comment2 "License: CC by 4.0"
Comment3 "Author: Jordan Aceto"
Comment4 ""
$EndDescr
$Sheet
S 5000 2050 1500 1500
U 5F120841
F0 "microcontroller" 50
F1 "microcontroller.sch" 50
F2 "DAC_out" O R 6500 2550 50 
F3 "resolution_CV_in" I L 5000 3250 50 
F4 "sample_rate_CV_in" I L 5000 3400 50 
F5 "ADC_in" I L 5000 2200 50 
$EndSheet
$Sheet
S 7000 4050 1500 1500
U 5F1224B4
F0 "power_supply" 50
F1 "power_supply.sch" 50
$EndSheet
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5F242118
P 1050 2200
F 0 "J1" H 968 2417 50  0000 C CNN
F 1 "audio_input" H 968 2326 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1050 2200 50  0001 C CNN
F 3 "~" H 1050 2200 50  0001 C CNN
	1    1050 2200
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5F2427AB
P 1350 2400
F 0 "#PWR0101" H 1350 2150 50  0001 C CNN
F 1 "GND" H 1355 2227 50  0000 C CNN
F 2 "" H 1350 2400 50  0001 C CNN
F 3 "" H 1350 2400 50  0001 C CNN
	1    1350 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 2400 1350 2300
Wire Wire Line
	1350 2300 1250 2300
Wire Wire Line
	10150 2450 10150 2350
Wire Wire Line
	5000 4200 4900 4200
Wire Wire Line
	4900 4200 4900 3250
Wire Wire Line
	4900 3250 5000 3250
Wire Wire Line
	5000 3400 4800 3400
Wire Wire Line
	4800 3400 4800 4350
Wire Wire Line
	4800 4350 5000 4350
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 5F20120B
P 6000 7300
F 0 "H2" H 6100 7349 50  0000 L CNN
F 1 "MountingHole_Pad" H 6100 7258 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 6000 7300 50  0001 C CNN
F 3 "~" H 6000 7300 50  0001 C CNN
	1    6000 7300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5F201718
P 6000 7400
F 0 "#PWR02" H 6000 7150 50  0001 C CNN
F 1 "GND" H 6005 7227 50  0000 C CNN
F 2 "" H 6000 7400 50  0001 C CNN
F 3 "" H 6000 7400 50  0001 C CNN
	1    6000 7400
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 5F201A9A
P 6000 6800
F 0 "H1" H 6100 6849 50  0000 L CNN
F 1 "MountingHole_Pad" H 6100 6758 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 6000 6800 50  0001 C CNN
F 3 "~" H 6000 6800 50  0001 C CNN
	1    6000 6800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5F201AA0
P 6000 6900
F 0 "#PWR01" H 6000 6650 50  0001 C CNN
F 1 "GND" H 6005 6727 50  0000 C CNN
F 2 "" H 6000 6900 50  0001 C CNN
F 3 "" H 6000 6900 50  0001 C CNN
	1    6000 6900
	1    0    0    -1  
$EndComp
$Sheet
S 8500 2050 1000 1050
U 5F3D7D32
F0 "expander" 50
F1 "expander.sch" 50
F2 "expander_in" I L 8500 2250 50 
F3 "expander_out" O R 9500 2600 50 
$EndSheet
Wire Wire Line
	10150 2350 10250 2350
$Comp
L power:GND #PWR0102
U 1 1 5F243C9B
P 10150 2450
F 0 "#PWR0102" H 10150 2200 50  0001 C CNN
F 1 "GND" H 10155 2277 50  0000 C CNN
F 2 "" H 10150 2450 50  0001 C CNN
F 3 "" H 10150 2450 50  0001 C CNN
	1    10150 2450
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5F243C95
P 10450 2250
F 0 "J2" H 10400 2500 50  0000 L CNN
F 1 "audio_output" H 10200 2400 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 10450 2250 50  0001 C CNN
F 3 "~" H 10450 2250 50  0001 C CNN
	1    10450 2250
	1    0    0    -1  
$EndComp
$Sheet
S 7000 2050 1000 1000
U 5F122464
F0 "low_pass_filter" 50
F1 "low_pass_filter.sch" 50
F2 "wet_from_DAC" I L 7000 2200 50 
F3 "low_passed_wet_signal" O R 8000 2550 50 
$EndSheet
Wire Wire Line
	1250 2200 2000 2200
$Sheet
S 3500 2050 1000 1000
U 5F122414
F0 "variable_gain_amp" 50
F1 "variable_gain_amp.sch" 50
F2 "audio_in" I L 3500 2200 50 
F3 "scaled_audio_out" O R 4500 2550 50 
$EndSheet
$Sheet
S 2000 2000 1000 1050
U 5F3D7CC8
F0 "compressor" 50
F1 "compressor.sch" 50
F2 "compressor_out" O R 3000 2550 50 
F3 "compressor_in" I L 2000 2200 50 
$EndSheet
Wire Wire Line
	3000 2550 3250 2550
Wire Wire Line
	3250 2550 3250 2200
Wire Wire Line
	3250 2200 3500 2200
Wire Wire Line
	4500 2550 4750 2550
Wire Wire Line
	4750 2550 4750 2200
Wire Wire Line
	4750 2200 5000 2200
Wire Wire Line
	6500 2550 6750 2550
Wire Wire Line
	6750 2550 6750 2200
Wire Wire Line
	6750 2200 7000 2200
Wire Wire Line
	8000 2550 8250 2550
Wire Wire Line
	8250 2550 8250 2250
Wire Wire Line
	8250 2250 8500 2250
$Sheet
S 5000 4050 1500 1500
U 5F1223E3
F0 "control_voltage_generator" 50
F1 "control_voltage_generator.sch" 50
F2 "resolution_CV_out" O L 5000 4200 50 
F3 "sample_rate_CV_out" O L 5000 4350 50 
$EndSheet
Wire Wire Line
	9500 2600 9750 2600
Wire Wire Line
	9750 2600 9750 2250
Wire Wire Line
	9750 2250 10250 2250
$EndSCHEMATC
