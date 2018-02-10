var arr = ['a', 'b', 'c', 'd'];
console.log(arr.length);

arr.push('a');
console.log(arr);
arr.unshift('z'); //앞에 추가
console.log(arr);

arr.shift(); //첫번째 배열 제거
console.log(arr);
arr.pop(); //마지막 배열 제거
console.log(arr);

arr.reverse();
console.log(arr);
arr.sort();
console.log(arr);

//slice
arr.splice(3,3); //3번 위치에서 3개 자름,
console.log(arr, arr.length);
delete arr[0]; // 0번 공간 유지 & 데이터삭제
console.log(arr, arr.length);
//

arr = ['a', 'b', 'c'];
var arr2 = [];
for (var i = 0; i < arr.length; i++) {
    arr2.push(arr[i]);
}
console.log(arr2);
