#
# Mettre ici le nom de votre programme 
# (il faut que dans OBJECTS il y ait au moins un objet de même nom que TARGET.
#
TARGET= voyageur

#
# Mettre ici l'ensemble des fichiers objets nécessaires aux programmes 
# (les fichiers peuvent être situés dans des répertoires)
#
OBJECTS= source/ville.o source/carte.o source/visite.o  source/main.o

#
# Mettre ici vos options de compilation.
#
CFLAGS= -DDEBUG -g -Wall -pedantic -lm `pkg-config --cflags MLV`

#
# Mettre ici les options qui devront être passées à l'éditeur de liens.
# Par exemple : -L/directory
#
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`

#
# Mettre ici les noms des bibliothèques et leurs locations.
# Par exemple : -lpthread
#
LDLIBS=`pkg-config --libs-only-l MLV`

 
###############################################################################

DEPENDS=$(OBJECTS:.o=.d)
INCLUDE_DEPENDS=$(foreach i,$(DEPENDS),$(wildcard $(i)))
 
all: $(TARGET)
 
$(TARGET): $(DEPENDS) $(OBJECTS)
	$(CC) -o $@ $(LDFLAGS) $(OBJECTS) $(LDLIBS)
 
%.d:%.c
	$(CC) -M $(CFLAGS) -MT '$(shell echo "$<" | sed 's,\($*\)\.c,\1.o $@,' )'  $< > $@
 
include $(INCLUDE_DEPENDS)
 
clean:
	-rm -f $(TARGET)
	-rm -f $(OBJECTS)
	-rm -f $(DEPENDS)
