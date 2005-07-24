/*
    i18nized by:  KUN-CHUNG, HSIEH <linuxer@coventive.com>
		  Taiwan

    Homepage: http://www.geocities.com/linux4tw/

    �{����ڤƳ]�p:  �±X��
*/

#include <features.h>
#ifndef __i18n__
   #define PKG "eject"
 # ifndef __UCLIBC__
   #define __i18n__
   #define LOCALEDIR "/usr/share/locale"

   #include <locale.h>
   #include <libintl.h>
   #define _(str) gettext (str)
   #define N_(str) (str)
   #define I18NCODE setlocale(LC_ALL,""); textdomain(PKG); bindtextdomain(PKG,LOCALEDIR);
 #else
   #define _(str) (str)
   #define N_(str) (str)
   #define I18NCODE
 #endif
   void i18n_init (void);
#endif

