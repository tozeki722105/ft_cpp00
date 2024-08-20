#!/bin/bash

# テスト対象のコマンド
readonly command_to_test="./a.out"

expect() {
  # 期待する出力
  local expected_output=$1

  # コマンドライン引数
  local command_args=("${@:2}")

  # コマンドを実行し、結果を変数に格納
  local actual_output=$($command_to_test "${command_args[@]}")

  # 期待する出力と実際の出力を比較
  if [[ "$actual_output" = "$expected_output" ]]; then
    echo "Test passed!"
  else
    echo "Test failed!"
    echo "Expected: \"$expected_output\""
    echo "Actual  : \"$actual_output\""
  fi
}

main() {
  expect "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
  expect "AAABBBCCC" "aaa" "bbb" "ccc"
  expect "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF." "Damnit" " ! " "Sorry students, I thought this thing was off."
  expect "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." "shhhhh... I think the students are asleep..."
  return 0
  
}

main "$@"