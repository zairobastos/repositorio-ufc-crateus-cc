function addClickListenerAndBlur(id, className) {
	let element = document.getElementById(id);
	let classElements = document.querySelectorAll("." + className);

	element.addEventListener("click", function () {
		classElements.forEach(function (e) {
			e.style.backgroundColor = "#00ff00";
		});
		element.style.backgroundColor = "#00ff00";
	});

	element.addEventListener("blur", function () {
		classElements.forEach(function (e) {
			e.style.backgroundColor = "#C4D2EB";
		});
		element.style.backgroundColor = "#C4D2EB";
	});
}

// Add event listeners for each element
addClickListenerAndBlur("fup", "fup");
addClickListenerAndBlur("calc", "calc");
addClickListenerAndBlur("cd", "cd");
addClickListenerAndBlur("mb", "mb");
addClickListenerAndBlur("poo", "poo");
addClickListenerAndBlur("ed", "ed");
addClickListenerAndBlur("md", "md");
addClickListenerAndBlur("al", "al");
addClickListenerAndBlur("arq", "arq");
addClickListenerAndBlur("so", "so");
addClickListenerAndBlur("bd", "bd");
addClickListenerAndBlur("log", "log");
addClickListenerAndBlur("aps", "aps");
addClickListenerAndBlur("lfa", "lfa");
addClickListenerAndBlur("web", "web");
addClickListenerAndBlur("graf", "graf");
addClickListenerAndBlur("paa", "paa");
addClickListenerAndBlur("es", "es");
addClickListenerAndBlur("es1", "es1");
addClickListenerAndBlur("tcc", "tcc");
