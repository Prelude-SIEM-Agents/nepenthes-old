# nepenthes module Makefile
# Paul Baecher, Maximillian Dornseif, Markus Koetter
# $Id: Makefile.am 556 2006-05-31 05:04:17Z common $

AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = -I$(top_srcdir)/nepenthes-core/include -I$(top_srcdir)/nepenthes-core/src -pipe -D _GNU_SOURCE
AM_CXXFLAGS = -Wall -Werror


pkglib_LTLIBRARIES = vulnupnp.la

vulnupnp_la_SOURCES = vuln-upnp.conf.dist UPNPDialogue.hpp vuln-upnp.hpp UPNPDialogue.cpp vuln-upnp.cpp

vulnupnp_la_LDFLAGS = -module -no-undefined -avoid-version
