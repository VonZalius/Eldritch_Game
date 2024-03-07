# Linux

# Name of the program.
NAME     := Game

# Sources and objects.
SRCS     := main.cpp Jeu.cpp Map.cpp Titre.cpp Attaques.cpp Gold.cpp Carte_de_jeu.cpp Paternes.cpp
OBJS     := $(SRCS:.cpp=.o)

# Define all the compiling flags.
CXX      := g++
CXXFLAGS := -Wall -Werror -Wextra

# Compile and create everything.
all: $(NAME)

# Compile the program with the objects.
$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# This won't run if the source files don't exist or are not modified.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# Rule to remove all the object files.
clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed!"

# Rule to remove everything that has been created by the makefile.
fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed!"

# Rule to re-make everything.
re:     fclean all

# Makes sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: all clean fclean format re