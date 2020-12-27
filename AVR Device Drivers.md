# AVR Device Drivers 
### Contentes
* Brief 
* Installtion instructions 
* How to use  ?
* Copy Rights  
* Bugs
* Change log
* Contact informations

### Brief
This is the frist verstion of ATMEGA32 device drivers 
the repo includes almost all internal prephral of atmega32 
the code designed to be porable with a separated file that includes the registers defintions and bits number 
there is some file to make code clean and organized like 
##### BIT_MATH.h
    This file has some macro that helping you to deal with individul     bits ex.  *SET_BIT(REGISTER,BITNUMBER)* , this macro enable you to set the value of bit 'BITNUMBER' to 1 without affecting to other bits in register
##### STD_TYPES.h
    This file has some user defined 'typedef' to make the size of the variables fixed when moving from compiler to another compiler like 
    u8 , s8 -> the 'u' represent 'unsigned' word and '8' represent the size in bits , and 's' represend 'signed' word
    so we hve "u8 x =0" is equal to "unsigned char x =0"  
##### Mem_Map32.h
    This file has the register defintions and bit number on each register and some macro

Then there are modules file's in layered architecture MCAL.

### Installtion instructions 
* These files does not requre any installion you only need to put them into your project file
Each driver consist of two or three modules or files 
> Frist file called "XXXX_interface.h"
This file includes the APIs for this module , you must open it to know how to use those functons 
in this module .
> Secound file called "XXXX_config.h" its exist for some modules 
Use this file to configure the settings and propreties of the module .
> Third file called "XXXX_program.c"
This file includes the APIs implementation for this module in c .
### How to use  ?
* To use this code you just put it on the project file and include whatever you want of XXXX_interface.h into your main to be able to use the APIs
thin you can change the configuration of each module in XXX.config.h file if avilable , but you will need to recompile your code *

### Copy Rights  
> This program is distributed in the hope  that it will be useful, you can use it for eductional purpose , you are not allowed to use it in a company or any commercial purpose without a written permission from me.
### Bugs
 Bugs will be listed here .
### Change log

> there is no change log till now .



#### Development
Want to contribute? Great!
Just contact me .

### Contact informations
Hello , I'm Eslam Ebrahim Shahin 
I'm an Embedded Software Engneer , I study in faculty of Navigation Sceince and Space Technology ,from Egypt
you can contact my through 
* [Linked in](https://www.linkedin.com/in/eslamshahin0/)
* Mail eslamshahin552000@gmail.com
