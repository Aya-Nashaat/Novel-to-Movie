document.addEventListener("DOMContentLoaded", function() {

// authors names elements 
var a = document.getElementById("a");
var b = document.getElementById("b");
var c = document.getElementById("c");
var d = document.getElementById("d");

// their bio s 
var first = document.getElementById("first");
var second = document.getElementById("second");
var third = document.getElementById("third");
var fourth = document.getElementById("fourth");

// listen to clicks on names 
a.addEventListener("click", function(){clickHandler("a");});
b.addEventListener("click", function(){clickHandler("b");});
c.addEventListener("click", function(){clickHandler("c");});
d.addEventListener("click", function(){clickHandler("d");});


function clickHandler(id){ 
  
  if(id  == a.id)
  {
    
    first.style.display = "block";
    second.style.display = "none";
    third.style.display = "none";
    fourth.style.display = "none";

  }
  else if (id  == b.id)
  {
    
    first.style.display = "none";
    second.style.display = "block";
    third.style.display = "none";
    fourth.style.display = "none";
  }
  else if (id  == c.id)
  {
    first.style.display = "none";
    second.style.display = "none";
    third.style.display = "block";
    fourth.style.display = "none";
  }
  else if (id  == d.id)
  {
    first.style.display = "none";
    second.style.display = "none";
    third.style.display = "none";
    fourth.style.display = "block";
  }
}
})
