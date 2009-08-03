#===- lib/x86_64/Makefile.mk -------------------------------*- Makefile -*--===#
#
#                     The LLVM Compiler Infrastructure
#
# This file is distributed under the University of Illinois Open Source
# License. See LICENSE.TXT for details.
#
#===------------------------------------------------------------------------===#

Dir := lib/x86_64
SubDirs := 
OnlyArchs := x86_64

AsmSources := $(foreach file,$(wildcard $(Dir)/*.s),$(notdir $(file)))
Sources := $(foreach file,$(wildcard $(Dir)/*.c),$(notdir $(file)))
ObjNames := $(Sources:%.c=%.o) $(AsmSources:%.s=%.o)
Target := Optimized

# FIXME: use automatic dependencies?
Dependencies := $(wildcard $(Dir)/*.h)

include make/subdir.mk