var counter =document.querySelector(".counter");
var followers =document.querySelector(".followers");


// counter.innerHTML=1001;
let count=1;
setInterval(()=>{
    if (count< 1000) {
        count++;
    counter.innerText=count + " Times";
    }
}
,1);


setTimeout(()=>{
  followers.innerText="Aishwarya"
},7000);

