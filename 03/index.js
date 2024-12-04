const { log } = require('node:console');
const fs = require('node:fs').promises;

const re = /(mul\(\d{1,3},\d{1,3}\))/g;



const main = async () => {
    try {
        let fileData = await fs.readFile('input.txt');
        // console.log(fileData + "ok");

        // console.log((fileData.toString()));
        fileData = fileData.toString()

        let numbers = []


        let m = true;
        while(m){
            m = re.exec(fileData);
            if(m){
                let num1 = m.toString().slice(4)
                let num1real = parseInt(num1)

                let commaIndex = m.toString().indexOf(",")
                let num2 = m.toString().slice(commaIndex+1)
                let num2real = parseInt(num2)
                
                numbers.push(mul(num1real, num2real))
            }
        }
        console.log(numbers.reduce((accumulator, currentValue) => accumulator + currentValue));
    } catch (err) {
        console.error("Error reading file:", err);
    }
};

const mul = (num1, num2) => {
    return num1 * num2
}

main()