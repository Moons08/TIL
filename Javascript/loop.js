var a = 0;
while (a<5) {
    a++;
    console.log(a);
}
//  | means or, && means and

for (var i = 2; i < 10; i++) {
    if (i===3 | i===4){
        continue;
    }
    for (var j = 1; j < 10; j++) {
        process.stdout.write(i+"x"+j+"="+i*j+"\t");
    }console.log("");
    if (i===7) {
        break;
    }
}

// process.stdout.write() 가로로 쭉 쓸때.
//
// for (var i = 1; i < 10; i++) {
//     for (var j = 2; j < 10; j++) {
//         process.stdout.write(j+"x"+i+"="+i*j+"\t");
//     }console.log("");
// }
