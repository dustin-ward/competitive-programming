var data = '[{"a":1,"b":2},{"c":3,"d":4}]';

var json = JSON.parse(data);

console.log(Object.values(json).reduce((a, b) => a + b, 0));
