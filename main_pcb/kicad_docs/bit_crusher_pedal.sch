EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 6
Title "Bit Crusher Pedal"
Date "2020-07-27"
Rev "0"
Comp ""
Comment1 "creativecommons.org/licenses/by/4.0/"
Comment2 "License: CC by 4.0"
Comment3 "Author: Jordan Aceto"
Comment4 ""
$EndDescr
$Sheet
S 5000 1500 1500 1500
U 5F120841
F0 "microcontroller" 50
F1 "microcontroller.sch" 50
F2 "DAC_out" O R 6500 1650 50 
F3 "resolution_CV_in" I L 5000 2700 50 
F4 "sample_rate_CV_in" I L 5000 2850 50 
F5 "ADC_in" I L 5000 1650 50 
$EndSheet
$Sheet
S 2500 1500 1500 1500
U 5F122414
F0 "audio_input" 50
F1 "audio_input.sch" 50
F2 "buffered_dry_audio" O R 4000 1650 50 
F3 "dry_audio_input" I L 2500 1650 50 
$EndSheet
$Sheet
S 7500 1500 1500 1500
U 5F122464
F0 "audio_output" 50
F1 "audio_output.sch" 50
F2 "wet_from_DAC" I L 7500 1650 50 
F3 "buffered_wet_audio" O R 9000 1650 50 
$EndSheet
$Sheet
S 7500 3500 1500 1500
U 5F1224B4
F0 "power_supply" 50
F1 "power_supply.sch" 50
$EndSheet
$Sheet
S 5000 3500 1500 1500
U 5F1223E3
F0 "control_voltage_generator" 50
F1 "control_voltage_generator.sch" 50
F2 "resolution_CV_out" O L 5000 3650 50 
F3 "sample_rate_CV_out" O L 5000 3800 50 
$EndSheet
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5F242118
P 1500 1650
F 0 "J1" H 1418 1867 50  0000 C CNN
F 1 "audio_input" H 1418 1776 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1500 1650 50  0001 C CNN
F 3 "~" H 1500 1650 50  0001 C CNN
	1    1500 1650
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5F2427AB
P 1800 1850
F 0 "#PWR0101" H 1800 1600 50  0001 C CNN
F 1 "GND" H 1805 1677 50  0000 C CNN
F 2 "" H 1800 1850 50  0001 C CNN
F 3 "" H 1800 1850 50  0001 C CNN
	1    1800 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1850 1800 1750
Wire Wire Line
	1800 1750 1700 1750
Wire Wire Line
	1700 1650 2500 1650
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5F243C95
P 10000 1650
F 0 "J2" H 9950 1900 50  0000 L CNN
F 1 "audio_output" H 9750 1800 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 10000 1650 50  0001 C CNN
F 3 "~" H 10000 1650 50  0001 C CNN
	1    10000 1650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5F243C9B
P 9700 1850
F 0 "#PWR0102" H 9700 1600 50  0001 C CNN
F 1 "GND" H 9705 1677 50  0000 C CNN
F 2 "" H 9700 1850 50  0001 C CNN
F 3 "" H 9700 1850 50  0001 C CNN
	1    9700 1850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9700 1850 9700 1750
Wire Wire Line
	9700 1750 9800 1750
Wire Wire Line
	9800 1650 9000 1650
Wire Wire Line
	4000 1650 5000 1650
Wire Wire Line
	6500 1650 7500 1650
Wire Wire Line
	5000 3650 4900 3650
Wire Wire Line
	4900 3650 4900 2700
Wire Wire Line
	4900 2700 5000 2700
Wire Wire Line
	5000 2850 4800 2850
Wire Wire Line
	4800 2850 4800 3800
Wire Wire Line
	4800 3800 5000 3800
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 5F20120B
P 10000 5550
F 0 "H2" H 10100 5599 50  0000 L CNN
F 1 "MountingHole_Pad" H 10100 5508 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 10000 5550 50  0001 C CNN
F 3 "~" H 10000 5550 50  0001 C CNN
	1    10000 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5F201718
P 10000 5650
F 0 "#PWR02" H 10000 5400 50  0001 C CNN
F 1 "GND" H 10005 5477 50  0000 C CNN
F 2 "" H 10000 5650 50  0001 C CNN
F 3 "" H 10000 5650 50  0001 C CNN
	1    10000 5650
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 5F201A9A
P 10000 5050
F 0 "H1" H 10100 5099 50  0000 L CNN
F 1 "MountingHole_Pad" H 10100 5008 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 10000 5050 50  0001 C CNN
F 3 "~" H 10000 5050 50  0001 C CNN
	1    10000 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5F201AA0
P 10000 5150
F 0 "#PWR01" H 10000 4900 50  0001 C CNN
F 1 "GND" H 10005 4977 50  0000 C CNN
F 2 "" H 10000 5150 50  0001 C CNN
F 3 "" H 10000 5150 50  0001 C CNN
	1    10000 5150
	1    0    0    -1  
$EndComp
$EndSCHEMATC
