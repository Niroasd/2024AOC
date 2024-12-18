const fs = require('node:fs').promises;

const re = /(mul\(\d{1,3},\d{1,3}\)|(do\(\))|don't\(\))/g;

const main = async () => {
    try {
        let allow = true
        let fileData = await fs.readFile('input.txt');
        fileData = fileData.toString()

        let numbers = []

        let m = true;
        while((m = re.exec(fileData)) !== null){
            if(m[0] === "do()"){
                allow = true;
                continue
            } else if(m[0] === "don't()"){
                allow = false;
                continue
            }
            if(m && allow){
                let num1 = m.toString().slice(4)
                let num1real = parseInt(num1)

                let commaIndex = m.toString().indexOf(",")
                let num2 = m.toString().slice(commaIndex+1)
                let num2real = parseInt(num2)
                
                numbers.push(mul(num1real, num2real))
            }
        }
        console.log(numbers.reduce((accumulator, currentValue) => accumulator + currentValue));
        return numbers.reduce((accumulator, currentValue) => accumulator + currentValue);
    } catch (err) {
        console.error("Error reading file:", err);
    }
};

const mul = (num1, num2) => {
    return num1 * num2
}

main()