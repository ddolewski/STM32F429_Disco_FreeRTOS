# STM32F429_Disco_FreeRTOS
Rozwojowy projekt FreeRTOS z wykorzystaniem różnych peryferiów mikrokontrolera STM32F429ZIT6 (STM32F429I-DISC1)

- FreeRTOS v9.0.0
- ST Periph V1.6.1 / 21-October-2015
- Discovery board drivers V1.0.1 / 28-October-2013

Program zawiera task odpowiadający za miganie diodą LED z f=1Hz oraz przełączanie buttonem stanu diody w przerwaniu EXTI0 (PA0)

W celu prawidłowego działania konfiguracji OpenOCD należy:

1) zainstalować plugin GNU ARM Eclipse OpenOCD z pakietu GNU ARM Eclipse Plug-ins
oraz pliki binarne OpenOCD z linków poniżej:

http://gnuarmeclipse.github.io/openocd/ - instalacja oraz konfiguracja 

http://gnuarmeclipse.sourceforge.net/updates - plugin eclipse

2) Skonfigurować poprawnie ustawienia Eclipse dla danego systemu operacyjnego (Linux/Windows/MacOS)
tzn. wskazać ścieżkę openocd i jego zależności oraz gdb (Window->Preferences->Run/Debug->String Substitution):

openocd_path

openocd_executable

gdb_path

gdp_executable

openocd_boards

