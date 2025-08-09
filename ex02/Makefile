#-----------EXECUTABLE-----------

NAME            :=        ex02.exe
#-----------DIR PATHS------------

SRC_DIR            :=        src/
OBJ_DIR            :=        obj/
INC_DIR            :=        inc/

#-----------CMP PARAM------------

MAKEFLAGS        :=        --no-print-directory
CXX = c++
CXXFLAGS =    -Wall -Wextra -Werror -std=c++98 -I inc

#-----------SHORT CUTS-----------

RM				:=		rm -f
SRC_FILES        =		Fixed \
						main

SRC             =         $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILES)))
OBJ             =         $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS             =         $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS            =         $(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))

#----------CACHE------------------
OBJF            =        .cache_exists
#---------------------------------

all:
	$(MAKE)	$(NAME)

-include    ${DEPS}
$(NAME):	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INCS) | $(OBJF)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

$(OBJF):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -rf $(OBJ_DIR)

fclean:	clean
	$(RM) -f $(NAME)


re:	fclean
	$(MAKE)

PHONY: all clean fclean re