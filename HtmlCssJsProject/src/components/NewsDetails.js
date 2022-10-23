import React from 'react'

const NewsDetails = ({ card, setCard }) => {
    return ( <
        div className = "newsdetails" >
        <
        h2 className = "heading" > { card.title } < /h2> <
        img className = "image"
        src = { card.urlToImage }
        alt = "" / >
        <
        div > < h4 className = "description" > { card.description } < /h4></div >
        <
        div > < h4 className = "content" > { card.content } < /h4></div >
        <
        h4 > Author: { card.author } < /h4> <
        /div>
    )
}

export default NewsDetails;