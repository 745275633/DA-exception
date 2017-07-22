## Introduction
### 宏
* `DA_THROW_0()` 抛出一个异常，包含抛出位置信息。
* `DA_THROW_1(message)` 抛出一个包含位置信息和 message	(std::string 属性) 的异常。
* `DA_THROW_3(name, type, message)` 抛出一个包含位置和自定义类型信息的异常，不过要给异常指定一个标识符。
* `DA_CATCH` 捕获异常，加入位置信息并继续传递。
* `DA_CATCH_STH(x)` 捕获异常，执行 x ，加入位置信息并继续传递。
* `DA_MAIN_CATCH` 捕获异常，把异常中的信息全部打印。
* `DA_MAIN_CATCH_ENDFUN(endfun)` 捕获异常，把异常中的信息全部打印，执行 endfun。

### 宏选项
* `DA_EXCEPTION` 定义此宏后可以省去上述宏中的 `DA`。如：用 `THROW_0()` 表示 `DA_THROW_0()`

