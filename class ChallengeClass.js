class ChallengeClass {
  IsValid(s) {
    if (s.includes('/') * s.includes('-')) {
      let tmp = s.split('/');
      let t = tmp[1].split('-');
      if (t[1].includes(t[0][1])) return 0;
    }
    return (s.includes('(') ^ s.includes(')') | /^[+\-*/]|[+\-*/]$/.test(s) | /([+\-*/]{2,})/.test(s)) ? 0 : 1;
  }
}
// Ví dụ lời gọi chương trình
const challenge = new ChallengeClass();
console.log(challenge.IsValid("3+2*(5-1)")); // Output: 1
console.log(challenge.IsValid("10/2+3)")); // Output: 0
console.log(challenge.IsValid("1++2")); // Output: 0
console.log(challenge.IsValid("5/(3-3)")); // Output: 0
console.log(challenge.IsValid("4-")); // Output: 0
console.log("hello world");