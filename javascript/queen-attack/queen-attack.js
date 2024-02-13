export class QueenAttack {
    constructor(position = {white: [0,3], black: [7,3]}) {
        this.white = position.white
        this.black = position.black

        if(this.white.every((v,i) => v === this.black[i])){
            throw new Error('Queens cannot share the same space')
        }
        
        this.posW = this.white[0] * 8 + this.white[1] 
        this.posB = this.black[0] * 8 + this.black[1]
    }
    
    toString() {
        let board = ''
        for(let i = 0; i < 64; i++) {
            if (this.posW == i)
                board += "W"
            else if (this.posB == i)
                board += "B"
            else
                board += '_'
            board += (i + 1) % 8 == 0 ? "\n" : " "
        }
        return board
    } 

    canAttack() {
        let diff = Math.abs(this.posW - this.posB)
        //horizontally
        if (this.white[0] == this.black[0])
            return true
        //vertically
        if (this.white[1] == this.black[1])
            return true
        //diagonally
        for (let i = 0; i < 8; i++){
            if(diff == (8 * i + i) || diff == (8 * i - i)) 
                return true
        }
        
        return false
    }
}
