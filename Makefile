build:
ifdef f
	@g++ -std=c++17 -Wshadow -Wall $(f).cpp -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -DLOCAL
else
	@g++ -std=c++17 -Wshadow -Wall a.cpp -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -DLOCAL
endif

clean:
	@rm -f *.out

create:
ifdef f
	@cp code/CP/template.cpp $(f).cpp
else
	@cp code/CP/template.cpp a.cpp
endif

run:
ifdef f
	@./a.out < $(f)
else
	@./a.out < in
endif
	@echo
