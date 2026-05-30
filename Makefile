all:
	g++ dfs_base.cpp -O2 -lm -lfmt -o dfs_base.out
	g++ dfs_arrange.cpp -O2 -lm -lfmt -o dfs_arrange.out
	g++ binary_search.cpp -O2 -lm -lfmt -o binary_search.out
	g++ sort_bubble.cpp -O2 -lm -lfmt -o sort_bubble.out
	g++ sort_selection.cpp -O2 -lm -lfmt -o sort_selection.out
clean:
	rm *.out
format:
	clang-format -style=Microsoft -i *.cpp
