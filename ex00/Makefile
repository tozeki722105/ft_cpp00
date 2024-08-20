# (1)コンパイラ
CXX  = c++
# (2)コンパイルオプション
CXXFLAGS    = -Wall -Wextra -Werror  -std=c++98
# (3)実行ファイル名
TARGET  = a.out
# (4)コンパイル対象のソースコード
SRCS    = megaphone.cpp
# (5)オブジェクトファイル名
OBJS    = $(SRCS:.cpp=.o)

# (6)インクルードファイルのあるディレクトリパス
INCDIR  = -I .

# (11)"make all"で make cleanとmakeを同時に実施。
all:$(TARGET)

# (9)ターゲットファイル生成
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ 

# (10)オブジェクトファイル生成
$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCDIR) -c $(SRCS)

run: all
	./$(TARGET) kKk lLl pPp
# (12).oファイル、実行ファイル、.dファイルを削除
clean:
	rm -f $(OBJS) $(TARGET)