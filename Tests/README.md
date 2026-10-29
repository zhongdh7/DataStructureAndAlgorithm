# Tests —— 测试代码集中存放区

本文件夹集中存放所有测试 / 验证代码，避免测试程序散落在工作区根目录。

## 组织方式

- 每个主题一个子文件夹：`Tests/<主题>/`
- 子文件夹内放可独立编译的源文件 + 简短 README（说明测试目标、运行命令、预期结果）。
- 命名建议：`test_<对象>.c`，例如 `test_singly_list.c`、`test_quick_sort.c`。

## 编译参考（Windows + gcc / MinGW）

```bat
gcc -std=c11 -Wall -Wextra -g test_xxx.c -o test_xxx.exe
```

## 说明

- `Tests/` 里的代码是验证性质的，不是正式实现；正式实现请看工作区根目录下的主题目录。
- 临时输出（`*.exe`、日志）可以留在对应测试子目录里，但不要提交到版本库（用 `.gitignore`）。
