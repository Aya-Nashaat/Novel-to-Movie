function SignUp()
{
  document.getElementById('SignUpForm').id="showSign";
}
/*all the form object of name[Form](ندهت على )
["A"]["B"]["C"]["D"](واللي ليهم اسم من الاسماء دي)
variable(وحطيت قيمة كل واحد في)
(وعملت تشيك على كل متغير اذا كان ليه قيمة  لو ملوش هيرجع اليرت لو ليه هيظهر الرساله)*/
function hideSign(inPut)
{
  var a=document.forms["Form"]["A"].value;
  var b=document.forms["Form"]["B"].value;
  var c=document.forms["Form"]["C"].value;
  var d=document.forms["Form"]["D"].value;
  if(a==null || a=="",b==null || b=="",c==null || c=="",d==null || d=="")
  {
    alert("Please fill all required fields");
    return false;
  }
  else
  {
    document.getElementById('showSign').style.display="none";
    document.getElementById('A').id="B";
  }
}
//----------------------------------------------------------------
function feedback()
{
 var x=document.getElementById('FB');
 var y=document.getElementById('H');
  if(x.checked)
  {
  y.style.display="inline";
  }
  else
  {
    y.style.display="none";
  }
}
function thanks()
{
  document.getElementById('container').style.display="none";
  document.getElementById('texthide').id="showText";
}
