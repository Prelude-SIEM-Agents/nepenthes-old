# nepenthes module Makefile
# Paul Baecher, Maximillian Dornseif, Markus Koetter
# $Id: Makefile.am 1357 2007-08-23 13:15:26Z common $

AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = -I$(top_srcdir)/nepenthes-core/include -I$(top_srcdir)/nepenthes-core/src -pipe -D _GNU_SOURCE
AM_CXXFLAGS = -Wall -Werror


pkglib_LTLIBRARIES = loghexdump.la

loghexdump_la_SOURCES = log-hexdump.cpp log-hexdump.hpp

loghexdump_la_LDFLAGS = -module -no-undefined -avoid-version
