// ==UserScript==
// @name 防颓插件
// @namespace shaber
// @version 0.1
// @description 克制一时的颓废欲望
// @author shaber
// @match https://www.bilibili.com/
// @match https://.zhihu.com/*
// @grant none
// ==/UserScript==

(function () {
	'use strict';
	if (prompt('颓尼玛呢', "") != "dqyakioi") {
		window.location.href = 'http://www.lydsy.com/';
	} else {
		alert("Yes he does!");
	}
})();