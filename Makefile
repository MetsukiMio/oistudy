all:
	g++ dfs_base.cpp -lfmt -o dfs_base.out
	g++ dfs_arrange.cpp -lfmt -o dfs_arrange.out
	g++ binary_search.cpp -lfmt -o binary_search.out
clean:
	rm *.out
format:
	clang-format -style=Microsoft -i *.cpp
