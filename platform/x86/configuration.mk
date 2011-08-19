## \file platform/x86/configuration.mk
##
## \brief Provides the configuration parameters specific to x86.
##
## \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
##
## To the extent possible under law, the author(s) have dedicated all copyright and related and
## neighboring rights to this software to the public domain worldwide. This software is distributed
## without any warranty.
##
## You should have received a copy of the CC0 Public Domain Dedication along with this software.
## If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

# Division Types
TYPE_DIVISION                   := struct { int quot, rem; }
TYPE_LONG_DIVISION              := struct { long int quot, rem; }
TYPE_LONG_LONG_DIVISION         := struct { long long int quot, rem; }
