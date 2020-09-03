########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized.
CC = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wsign-conversion -Weffc++  -Werror
LDFLAGS = 

# Warning level description
#
# -Wall		:	enables all the warinings about constructions
# -Wextra	:	enables some extra waring flags that are not enabled by -Wall
# -Wsign-conversion:	Warn for implicit conversions that may change the sign of an integer value
# -Werror	:	treat warnings as errors -	unused parameter ‘name’ -  [-Werror=unused-parameter]
# -Weffc++	:	a member should be initialized in the member initialization list

# More info :	https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html

# Makefile settings - Can be customized.
APPNAME = SimpleGame

MKDIR_P = mkdir -p obj
${OUT_DIR}:${MKDIR_P} ${OUT_DIR}

EXT = .cpp
SRCDIR = src
OBJDIR = obj
DEPDIR = dep

############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(DEPDIR)/%.d)
# UNIX-based OS variables & settings
# -d	:	delete empty folders
RM = rm -d		
DELOBJ = $(OBJ)
# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(APPNAME)

# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Creates the dependecy rules
# Create a separate folder for .d files 
$(DEPDIR)/%.d: $(SRCDIR)/%$(EXT)
	$(shell mkdir -p dep)	
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

# Includes all .h files
-include $(DEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
# Also create the obj directory
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(shell mkdir -p obj)	
	$(CC) $(CXXFLAGS) -o $@ -c $<

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DEP) $(APPNAME) $(DEPDIR)	$(OBJDIR)

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP)

#################### Cleaning rules for Windows OS #####################
# Cleans complete project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(DEP) $(APPNAME)$(EXE)

# Cleans only all files with the extension .d
.PHONY: cleandepw
cleandepw:
	$(DEL) $(DEP)