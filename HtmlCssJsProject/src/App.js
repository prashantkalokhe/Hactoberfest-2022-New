import React, { useState, useEffect } from 'react';
import NewsApi from './components/newsApi';
import NavBar from './components/NavBar';
import NewsDetails from './components/NewsDetails';
import Footer from './components/Footer';
import Error from './components/Error';
import './App.css';
import {
    BrowserRouter as Router,
    Switch,
    Route
} from "react-router-dom";

const App = () => {
    const [card, setCard] = useState({})
    useEffect(() => {
        // console.log(card)
    }, [card])

    return (

        <
        Router >
        <
        div className = "App" >
        <
        NavBar / >
        <
        Switch >
        <
        Route path = "/:title" > < NewsDetails card = { card }
        setCard = { setCard }
        /></Route >
        <
        Route path = "/"
        exact > < NewsApi card = { card }
        setCard = { setCard }
        /></Route >
        <
        Route component = { Error }
        /> <
        /Switch> <
        Footer / >
        <
        /div> <
        /Router>
    );

};

export default App;