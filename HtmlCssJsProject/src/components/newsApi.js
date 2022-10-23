import React, { useState, useEffect } from 'react'

import Card from '@mui/material/Card';
import CardContent from '@mui/material/CardContent';
import CardMedia from '@mui/material/CardMedia';
import Typography from '@mui/material/Typography';
import Grid from '@mui/material/Grid';
import Box from '@mui/material/Box';
import { Link } from 'react-router-dom'
import Pagination from '@mui/material/Pagination';
import { Button, CardActionArea, CardActions } from '@mui/material';

const NewsApi = ({ card, setCard }) => {
    const [page, setPage] = useState(1);
    const [newsData, setNewsData] = useState([]);

    // console.log(newsData);

    useEffect(() => {
        (async() => {
            let userData;
            try {
                const response = await fetch("https://saurav.tech/NewsAPI/top-headlines/category/health/in.json");
                userData = (await response.json());
                // console.log(userData)


            } catch (error) {
                console.log(error);
                userData = [];
            }
            setNewsData(userData.articles);

        })();
    }, []);

    function handleChange(event, value) {
        // console.log(value);
        setPage(value);
    }

    return (

        <
        div className = "page" > < h1 > Top News
        for the Day < /h1>

        <
        div className = "cards-container" >
        <
        Pagination className = "pagination"
        count = { 16 }
        color = "secondary"
        page = { page }
        onChange = { handleChange }
        /> <
        Box sx = {
            { flexGrow: 5, flexDirection: "column" } }
        className = "box" >

        <
        Grid container spacing = {
            { xs: 2, md: 3 } }
        columns = {
            { xs: 4, sm: 8, md: 12 } } > {
            newsData.slice((page - 1) * 4, page * 4).map((user, index) => {
                return (

                    <
                    Grid item xs = { 4 }
                    sm = { 4 }
                    md = { 3 }
                    key = { index } >
                    <
                    >
                    <
                    div className = "row" >
                    <
                    Card sx = {
                        { maxWidth: 345 } }
                    className = "card" >
                    <
                    CardActionArea >
                    <
                    CardMedia component = "img"
                    height = "140"

                    image = { user.urlToImage }
                    alt = "this is an image" /
                    >
                    <
                    CardContent >
                    <
                    Typography gutterBottom variant = "h5"
                    component = "div" > { user.title } <
                    /Typography> <
                    Typography variant = "body2"
                    color = "text.secondary" > { user.author } <
                    /Typography> <
                    Typography variant = "body2"
                    color = "text.secondary" >
                    Published At: { user.publishedAt } <
                    /Typography> <
                    /CardContent> <
                    /CardActionArea> <
                    CardActions >
                    <
                    Button size = "small"
                    color = "primary"
                    onClick = {
                        () => { setCard(user) } } >
                    <
                    Link to = { user.title.replaceAll(" ", "+").replaceAll("%", " ") } > LEARN MORE < /Link> <
                    /Button> <
                    /CardActions> <
                    /Card> <
                    /div> <
                    /> <
                    /Grid>
                )
            })
        } <
        /Grid> <
        /Box>   <
        /div> <
        /div> 

    )
}


export default NewsApi