# <div align="center">plutonium-http</div>

<div align="center">
    <img src="https://img.shields.io/badge/License-MIT-important?style=flat-square" />
    <img src="https://img.shields.io/badge/%E2%80%8E-C++-00599C?style=flat-square&logoWidth=20&logo=image/svg+xml;base64,PHN2ZyByb2xlPSJpbWciIHZpZXdCb3g9IjAgMCAyNCAyNCIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj48dGl0bGU+QysrIGljb248L3RpdGxlPjxwYXRoIGZpbGw9IndoaXRlIiBkPSJNMjIuMzkzIDZjLS4xNjctLjI5LS4zOTgtLjU0My0uNjUyLS42OUwxMi45MjUuMjJjLS41MDgtLjI5My0xLjMzOS0uMjkzLTEuODQ3IDBMMi4yNiA1LjMxYy0uNTA4LjI5My0uOTIzIDEuMDEzLS45MjMgMS42djEwLjE4YzAgLjI5NC4xMDQuNjIuMjcxLjkxLjE2Ny4yOS4zOTguNTQzLjY1Mi42ODlsOC44MTYgNS4wOTFjLjUwOC4yOTMgMS4zMzkuMjkzIDEuODQ3IDBsOC44MTYtNS4wOTFjLjI1NC0uMTQ2LjQ4NS0uMzk5LjY1Mi0uNjg5cy4yNzEtLjYxNi4yNzEtLjkxVjYuOTFjLjAwMi0uMjk0LS4xMDItLjYyLS4yNjktLjkxek0xMiAxOS4xMDljLTMuOTIgMC03LjEwOS0zLjE4OS03LjEwOS03LjEwOVM4LjA4IDQuODkxIDEyIDQuODkxYTcuMTMzIDcuMTMzIDAgMCAxIDYuMTU2IDMuNTUybC0zLjA3NiAxLjc4MUEzLjU2NyAzLjU2NyAwIDAgMCAxMiA4LjQ0NWMtMS45NiAwLTMuNTU0IDEuNTk1LTMuNTU0IDMuNTU1UzEwLjA0IDE1LjU1NSAxMiAxNS41NTVhMy41NyAzLjU3IDAgMCAwIDMuMDgtMS43NzhsMy4wNzcgMS43OEE3LjEzNSA3LjEzNSAwIDAgMSAxMiAxOS4xMDl6bTcuMTA5LTYuNzE0aC0uNzl2Ljc5aC0uNzl2LS43OWgtLjc5di0uNzloLjc5di0uNzloLjc5di43OWguNzl2Ljc5em0yLjk2MiAwaC0uNzl2Ljc5aC0uNzl2LS43OWgtLjc4OXYtLjc5aC43ODl2LS43OWguNzl2Ljc5aC43OXYuNzl6Ii8+PC9zdmc+" />
    <br/><br/>
    Making it possible to do basic http GET, POST, PUT & DELETE requests within ChaiScript.<br/>
    This plugin was mainly built for <a href="https://plutonium.pw/">Plutonium MW3</a>.
</div>

___

## Download

Download the [latest release](https://github.com/ryanocf/plutonium-http/releases) and put the <kbd>**plutonium-http.dll**</kbd> in your servers plugin folder.

___

## Usage

:exclamation: **OpenSSL is currently not supported.**<br/>
Every function returns the same Vector scheme:

```c++
0: version // String
1: error // String
2: status // Int
3: reason // String
4: body // String
5: headers // Map
```

```c++
/*
 * Params
 * url: String
 * route: String
 * headers: Map
 *
 * return: Vector
 */
http_get("http://example.com", "/route", ["header": "value"]);
```

```c++
/*
 * Params
 * url: String
 * route: String
 * body: String
 * headers: Map
 * content_type: String
 *
 * return: Vector
 */
http_post("http://example.com", "/route", "body", ["header": "value"], "text/plain");
http_post("http://example.com", "/route", "param=body&format=string", ["header": "value"], "application/x-www-form-urlencoded");
```

```c++
/*
 * Params
 * url: String
 * route: String
 * body: String
 * headers: Map
 * content_type: String
 *
 * return: Vector
 */
http_put("http://example.com", "/route", "body", ["header": "value"], "text/plain");
http_put("http://example.com", "/route", "param=body&format=string", ["header": "value"], "application/x-www-form-urlencoded");
```

```c++
/*
 * Params
 * url: String
 * route: String
 * body: String
 * headers: Map
 * content_type: String
 *
 * return: Vector
 */
http_delete("http://example.com", "/route", "body", ["header": "value"], "text/plain");
http_delete("http://example.com", "/route", "param=body&format=string", ["header": "value"], "application/x-www-form-urlencoded");
```

___

## Errors

```c++
std::array<std::string, 13> error_list = {
    "Success",
    "Unknown",
    "Connection",
    "BindIPAddress",
    "Read",
    "Write",
    "ExceedRedirectCount",
    "Canceled",
    "SSLConnection",
    "SSLLoadingCerts",
    "SSLServerVerification",
    "UnsupportedMultipartBoundaryChars",
    "Compression"
};
```

___

Any questions or problems?<br/>
Feel free to open an [issue](https://github.com/ryanocf/plutonium-http/issues/new) or visit this project on [Plutonium](https://forum.plutonium.pw/topic/6755/release-plutonium-http).

## Credits

https://github.com/yhirose/cpp-httplib<br/>
https://github.com/ChaiScript/ChaiScript<br/>
https://github.com/xensik/plutoscript
