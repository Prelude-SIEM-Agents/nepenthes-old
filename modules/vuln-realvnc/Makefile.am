# nepenthes module Makefile
# Paul Baecher, Maximillian Dornseif, Markus Koetter
# $Id: Makefile.am 561 2006-06-02 10:41:21Z common $

AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = -I$(top_srcdir)/nepenthes-core/include -I$(top_srcdir)/nepenthes-core/src -pipe -D _GNU_SOURCE
AM_CXXFLAGS = -Wall -Werror


pkglib_LTLIBRARIES = vulnrealvnc.la

vulnrealvnc_la_SOURCES = vuln-realvnc.cpp vuln-realvnc.hpp

vulnrealvnc_la_LDFLAGS = -module -no-undefined -avoid-version
