#
noinst_LIBRARIES	= libing2ofx.a
libing2ofx_a_SOURCES	= Account.h
libing2ofx_a_SOURCES	+= Account.cpp
libing2ofx_a_SOURCES	+= OutputFormat.h
libing2ofx_a_SOURCES	+= OutputFormat.cpp
libing2ofx_a_SOURCES	+= ReadCsvFile.h
libing2ofx_a_SOURCES	+= ReadCsvFile.cpp

bin_PROGRAMS		= ing2ofx
ing2ofx_SOURCES		= ing2ofx.cpp
ing2ofx_SOURCES		+= Options.h
ing2ofx_SOURCES		+= Options.cpp
ing2ofx_CPPFLAGS	= -DDEFAULT_FORMAT=OFX
ing2ofx_LDADD		= libing2ofx.a

bin_PROGRAMS		+= ing2mt940
ing2mt940_SOURCES	= ing2ofx.cpp
ing2mt940_SOURCES	+= Options.h
ing2mt940_SOURCES	+= Options.cpp
ing2mt940_CPPFLAGS	= -DDEFAULT_FORMAT=MT940
ing2mt940_LDADD		= libing2ofx.a
